/* 
 * Adium is the legal property of its developers, whose names are listed in the copyright file included
 * with this source distribution.
 * 
 * This program is free software; you can redistribute it and/or modify it under the terms of the GNU
 * General Public License as published by the Free Software Foundation; either version 2 of the License,
 * or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
 * Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along with this program; if not,
 * write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#import "AITwitterURLParser.h"
#import <AIUtilities/AIAttributedStringAdditions.h>
#import <AIUtilities/AIStringAdditions.h>

@implementation AITwitterURLParser

+(NSAttributedString *)linkifiedAttributedStringFromString:(NSAttributedString *)inString
{	
	NSAttributedString *attributedString;
	
	attributedString = [AITwitterURLParser linkifiedStringFromAttributedString:inString
														  forPrefixCharacter:@"@"
															   withURLFormat:@"http://www.twitter.com/%@"
															validCharacterSet:[NSCharacterSet characterSetWithCharactersInString:@"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_"]];
	
	NSMutableCharacterSet	*disallowedCharacters = [[NSCharacterSet punctuationCharacterSet] mutableCopy];
	[disallowedCharacters formUnionWithCharacterSet:[NSCharacterSet whitespaceCharacterSet]];
	
	attributedString = [AITwitterURLParser linkifiedStringFromAttributedString:attributedString
														   forPrefixCharacter:@"#"
																withURLFormat:@"http://search.twitter.com/search?q=%%23%@"
															validCharacterSet:[disallowedCharacters invertedSet]];
	
	return attributedString;
}

+(NSAttributedString *)linkifiedStringFromAttributedString:(NSAttributedString *)inString
										forPrefixCharacter:(NSString *)prefixCharacter
												   withURLFormat:(NSString *)inURLFormat
											   validCharacterSet:(NSCharacterSet *)validValues
{
	NSMutableAttributedString	*newString = [inString mutableCopy];
	
	NSScanner		*scanner = [NSScanner scannerWithString:[inString string]];
	
	NSString *trash;
	
	[newString beginEditing];
	
	while(![scanner isAtEnd]) {
		[scanner scanUpToString:prefixCharacter intoString:&trash];
		
		if([scanner isAtEnd]) {
			break;
		}
		
		NSUInteger	startLocation = [scanner scanLocation]+1;
		NSString	*linkText;
		
		[scanner setScanLocation:startLocation];
		[scanner scanUpToCharactersFromSet:[validValues invertedSet] intoString:&linkText];
		
		NSUInteger endLocation = [scanner scanLocation];
			
		[newString addAttribute:NSLinkAttributeName
						  value:[NSString stringWithFormat:inURLFormat, [linkText stringByEncodingURLEscapes]]
						  range:NSMakeRange(startLocation, endLocation - startLocation)];
	}
	
	[newString endEditing];
	
	return [newString autorelease];
}

@end