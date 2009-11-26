
#ifndef __purple_smarshal_MARSHAL_H__
#define __purple_smarshal_MARSHAL_H__

#include	<glib-object.h>

G_BEGIN_DECLS

/* VOID:POINTER,POINTER,OBJECT (/Users/adium/adium-1.4/Utilities/dep-build-scripts/source/im.pidgin.adium.1-4/libpurple/marshallers.list:1) */
extern void purple_smarshal_VOID__POINTER_POINTER_OBJECT (GClosure     *closure,
                                                          GValue       *return_value,
                                                          guint         n_param_values,
                                                          const GValue *param_values,
                                                          gpointer      invocation_hint,
                                                          gpointer      marshal_data);

/* BOOLEAN:OBJECT,POINTER,STRING (/Users/adium/adium-1.4/Utilities/dep-build-scripts/source/im.pidgin.adium.1-4/libpurple/marshallers.list:2) */
extern void purple_smarshal_BOOLEAN__OBJECT_POINTER_STRING (GClosure     *closure,
                                                            GValue       *return_value,
                                                            guint         n_param_values,
                                                            const GValue *param_values,
                                                            gpointer      invocation_hint,
                                                            gpointer      marshal_data);

/* VOID:STRING,STRING (/Users/adium/adium-1.4/Utilities/dep-build-scripts/source/im.pidgin.adium.1-4/libpurple/marshallers.list:3) */
extern void purple_smarshal_VOID__STRING_STRING (GClosure     *closure,
                                                 GValue       *return_value,
                                                 guint         n_param_values,
                                                 const GValue *param_values,
                                                 gpointer      invocation_hint,
                                                 gpointer      marshal_data);

/* VOID:STRING,STRING,DOUBLE (/Users/adium/adium-1.4/Utilities/dep-build-scripts/source/im.pidgin.adium.1-4/libpurple/marshallers.list:4) */
extern void purple_smarshal_VOID__STRING_STRING_DOUBLE (GClosure     *closure,
                                                        GValue       *return_value,
                                                        guint         n_param_values,
                                                        const GValue *param_values,
                                                        gpointer      invocation_hint,
                                                        gpointer      marshal_data);

/* VOID:ENUM,STRING,STRING (/Users/adium/adium-1.4/Utilities/dep-build-scripts/source/im.pidgin.adium.1-4/libpurple/marshallers.list:5) */
extern void purple_smarshal_VOID__ENUM_STRING_STRING (GClosure     *closure,
                                                      GValue       *return_value,
                                                      guint         n_param_values,
                                                      const GValue *param_values,
                                                      gpointer      invocation_hint,
                                                      gpointer      marshal_data);

/* VOID:ENUM,STRING,STRING,BOOLEAN (/Users/adium/adium-1.4/Utilities/dep-build-scripts/source/im.pidgin.adium.1-4/libpurple/marshallers.list:6) */
extern void purple_smarshal_VOID__ENUM_STRING_STRING_BOOLEAN (GClosure     *closure,
                                                              GValue       *return_value,
                                                              guint         n_param_values,
                                                              const GValue *param_values,
                                                              gpointer      invocation_hint,
                                                              gpointer      marshal_data);

G_END_DECLS

#endif /* __purple_smarshal_MARSHAL_H__ */
