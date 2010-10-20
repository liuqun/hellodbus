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

static gpointer test_obj_parent_class = NULL;

static void test_obj_class_intern_init (gpointer klass)
{
	test_obj_parent_class = g_type_class_peek_parent (klass);
	test_obj_class_init ((TestObjClass *) klass);
}

GType test_obj_get_type (void)
{
	static volatile gsize g_define_type_id__volatile = 0;
	if (g_once_init_enter (&g_define_type_id__volatile))
	{
		GType g_define_type_id = g_type_register_static_simple (
			G_TYPE_OBJECT,
			g_intern_static_string ("TestObj"),
			sizeof (TestObjClass),
			(GClassInitFunc) test_obj_class_intern_init,
			sizeof (TestObj),
			(GInstanceInitFunc) test_obj_init,
			(GTypeFlags) 0);
		g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
	}
	return g_define_type_id__volatile;
}

gboolean test_obj_add (TestObj *obj, int num1, int num2, int *sum, GError **error)
{
  *sum = num1 + num2;
  return TRUE;
}


