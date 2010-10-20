#include <glib-object.h>
#include <glib/gtypes.h>
#include <glib/gerror.h>
#include "testobj.h"

struct TestObj
{
  GObject parent;
};

struct TestObjClass
{
  GObjectClass parent;
};

static void test_obj_init (TestObj *obj)
{
}

static void test_obj_class_init (TestObjClass *klass)
{
}
G_DEFINE_TYPE(TestObj, test_obj, G_TYPE_OBJECT)

gboolean test_obj_add (TestObj *obj, int num1, int num2, int *sum, GError **error)
{
  *sum = num1 + num2;
  return TRUE;
}


