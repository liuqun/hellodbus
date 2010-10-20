#ifndef TESTOBJ_H
#include <glib/gtypes.h>

typedef struct TestObj TestObj;
typedef struct TestObjClass TestObjClass;

GType test_obj_get_type (void);
gboolean test_obj_add (TestObj *obj, int num1, int num2, int *sum, GError **error);

#define TEST_TYPE_OBJECT              (test_obj_get_type ())
#define TEST_OBJECT(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), TEST_TYPE_OBJECT, TestObj))
#define TEST_OBJECT_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), TEST_TYPE_OBJECT, TestObjClass))
#define TEST_IS_OBJECT(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), TEST_TYPE_OBJECT))
#define TEST_IS_OBJECT_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), TEST_TYPE_OBJECT))
#define TEST_OBJECT_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), TEST_TYPE_OBJECT, TestObjClass))

#endif//TESTOBJ_H
