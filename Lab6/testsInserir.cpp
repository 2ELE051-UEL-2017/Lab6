#include "gtest/gtest.h"

extern "C" {
#include "ll.h"
}

TEST(Inserir, ListaVazia)
{
	struct lld ll;
	int dado[1] = { 0 };

	ll_inicializar(&ll);

	ll_inserir(&ll, NULL, &dado[0]);

	ASSERT_NE((struct lld_el*)NULL, ll.inicio);
	ASSERT_NE((struct lld_el*)NULL, ll.fim);
	ASSERT_EQ(ll.inicio, ll.fim);

	ASSERT_EQ(NULL, ll.inicio->ant);
	ASSERT_EQ(NULL, ll.inicio->prox);

	ASSERT_EQ(&dado[0], ll.inicio->dado);

	ll_remover(&ll, ll.inicio);
}

TEST(Inserir, Lista2ElementosInsereInicio)
{
	struct lld ll;
	int dado[2] = { 0, 1 };

	ll_inicializar(&ll);

	ll_inserir(&ll, NULL, &dado[0]);
	ll_inserir(&ll, NULL, &dado[1]);

	ASSERT_NE((struct lld_el*)NULL, ll.inicio);
	ASSERT_NE((struct lld_el*)NULL, ll.fim);
	ASSERT_NE(ll.inicio, ll.fim);

	ASSERT_EQ(NULL, ll.inicio->ant);
	ASSERT_EQ(ll.fim, ll.inicio->prox);
	ASSERT_EQ(ll.inicio, ll.fim->ant);
	ASSERT_EQ(NULL, ll.fim->prox);

	ASSERT_EQ(&dado[1], ll.inicio->dado);
	ASSERT_EQ(&dado[0], ll.inicio->prox->dado);

	ll_remover(&ll, ll.fim);
	ll_remover(&ll, ll.inicio);
}

TEST(Inserir, Lista2ElementosInsereFim)
{
	struct lld ll;
	int dado[2] = { 0, 1 };

	ll_inicializar(&ll);

	ll_inserir(&ll, NULL, &dado[0]);
	ll_inserir(&ll, ll.inicio, &dado[1]);

	ASSERT_NE((struct lld_el*)NULL, ll.inicio);
	ASSERT_NE((struct lld_el*)NULL, ll.fim);
	ASSERT_NE(ll.inicio, ll.fim);

	ASSERT_EQ(NULL, ll.inicio->ant);
	ASSERT_EQ(ll.fim, ll.inicio->prox);
	ASSERT_EQ(ll.inicio, ll.fim->ant);
	ASSERT_EQ(NULL, ll.fim->prox);

	ASSERT_EQ(&dado[0], ll.inicio->dado);
	ASSERT_EQ(&dado[1], ll.inicio->prox->dado);

	ll_remover(&ll, ll.fim);
	ll_remover(&ll, ll.inicio);
}

TEST(Inserir, Lista3ElementosInsereInicioInicio)
{
	struct lld ll;
	int dado[3] = { 0, 1, 2 };

	ll_inicializar(&ll);

	ll_inserir(&ll, NULL, &dado[0]);
	ll_inserir(&ll, NULL, &dado[1]);
	ll_inserir(&ll, NULL, &dado[2]);

	ASSERT_NE((struct lld_el*)NULL, ll.inicio);
	ASSERT_NE((struct lld_el*)NULL, ll.fim);
	ASSERT_NE(ll.inicio, ll.fim);

	ASSERT_EQ(NULL, ll.inicio->ant);
	ASSERT_EQ(ll.inicio, ll.inicio->prox->ant);
	ASSERT_EQ(ll.fim->ant, ll.inicio->prox);
	ASSERT_EQ(ll.fim, ll.inicio->prox->prox);
	ASSERT_EQ(NULL, ll.fim->prox);

	ASSERT_EQ(&dado[2], ll.inicio->dado);
	ASSERT_EQ(&dado[1], ll.inicio->prox->dado);
	ASSERT_EQ(&dado[0], ll.inicio->prox->prox->dado);

	ll_remover(&ll, ll.inicio);
	ll_remover(&ll, ll.inicio);
	ll_remover(&ll, ll.inicio);
}

TEST(Inserir, Lista3ElementosInsereInicioMioloFim)
{
	struct lld ll;
	int dado[3] = { 0, 1, 2 };

	ll_inicializar(&ll);

	ll_inserir(&ll, NULL, &dado[0]);
	ll_inserir(&ll, ll.fim, &dado[1]);
	ll_inserir(&ll, ll.inicio, &dado[2]);

	ASSERT_NE((struct lld_el*)NULL, ll.inicio);
	ASSERT_NE((struct lld_el*)NULL, ll.fim);
	ASSERT_NE(ll.inicio, ll.fim);

	ASSERT_EQ(NULL, ll.inicio->ant);
	ASSERT_EQ(ll.inicio, ll.inicio->prox->ant);
	ASSERT_EQ(ll.fim->ant, ll.inicio->prox);
	ASSERT_EQ(ll.fim, ll.inicio->prox->prox);
	ASSERT_EQ(NULL, ll.fim->prox);

	ASSERT_EQ(&dado[0], ll.inicio->dado);
	ASSERT_EQ(&dado[2], ll.inicio->prox->dado);
	ASSERT_EQ(&dado[1], ll.inicio->prox->prox->dado);

	ll_remover(&ll, ll.inicio);
	ll_remover(&ll, ll.inicio);
	ll_remover(&ll, ll.inicio);
}
