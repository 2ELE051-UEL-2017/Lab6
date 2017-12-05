#include "gtest/gtest.h"

extern "C" {
#include "ll.h"
}

TEST(Inicializar, Inicializar)
{
	struct lld ll;

	ll_inicializar(&ll);

	ASSERT_EQ(NULL, ll.inicio);
	ASSERT_EQ(NULL, ll.fim);
}
