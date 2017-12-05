#include "gtest/gtest.h"

extern "C" {
#include "ll.h"
}

TEST(Remover, Lista1Elemento)
{
	struct lld ll;
	int dado[1] = { 0 };

	ll_inicializar(&ll);

	ll_inserir(&ll, NULL, &dado[0]);

	ll_remover(&ll, ll.inicio);

	ASSERT_EQ((struct lld_el*)NULL, ll.inicio);
	ASSERT_EQ((struct lld_el*)NULL, ll.fim);
}

TEST(Remover, Lista2ElementosRemovePrimeiro)
{
	struct lld ll;
	int dado[2] = { 0, 1 };

	ll_inicializar(&ll);

	ll_inserir(&ll, NULL, &dado[0]);
	ll_inserir(&ll, NULL, &dado[1]);

	ll_remover(&ll, ll.inicio);

	ASSERT_NE((struct lld_el*)NULL, ll.inicio);
	ASSERT_NE((struct lld_el*)NULL, ll.fim);
	ASSERT_EQ(ll.inicio, ll.fim);

	ASSERT_EQ(NULL, ll.inicio->ant);
	ASSERT_EQ(NULL, ll.fim->prox);

	ASSERT_EQ(&dado[0], ll.inicio->dado);

	ll_remover(&ll, ll.inicio);
}

TEST(Remover, Lista2ElementosRemoveUltimo)
{
	struct lld ll;
	int dado[2] = { 0, 1 };

	ll_inicializar(&ll);

	ll_inserir(&ll, NULL, &dado[0]);
	ll_inserir(&ll, NULL, &dado[1]);

	ll_remover(&ll, ll.fim);

	ASSERT_NE((struct lld_el*)NULL, ll.inicio);
	ASSERT_NE((struct lld_el*)NULL, ll.fim);
	ASSERT_EQ(ll.inicio, ll.fim);

	ASSERT_EQ(NULL, ll.inicio->ant);
	ASSERT_EQ(NULL, ll.fim->prox);

	ASSERT_EQ(&dado[1], ll.inicio->dado);

	ll_remover(&ll, ll.fim);
}

TEST(Remover, Lista3ElementosRemovePrimeiro)
{
	struct lld ll;
	int dado[2] = { 0, 1 };

	ll_inicializar(&ll);

	ll_inserir(&ll, NULL, &dado[0]);
	ll_inserir(&ll, NULL, &dado[1]);
	ll_inserir(&ll, NULL, &dado[2]);

	ll_remover(&ll, ll.inicio);

	ASSERT_NE((struct lld_el*)NULL, ll.inicio);
	ASSERT_NE((struct lld_el*)NULL, ll.fim);
	ASSERT_NE(ll.inicio, ll.fim);

	ASSERT_EQ(NULL, ll.inicio->ant);
	ASSERT_EQ(ll.fim, ll.inicio->prox);
	ASSERT_EQ(ll.inicio, ll.fim->ant);
	ASSERT_EQ(NULL, ll.fim->prox);

	ASSERT_EQ(&dado[1], ll.inicio->dado);
	ASSERT_EQ(&dado[0], ll.inicio->prox->dado);

	ll_remover(&ll, ll.inicio);
	ll_remover(&ll, ll.inicio);
}

TEST(Remover, Lista3ElementosRemovePrimeiroPrimeiro)
{
	struct lld ll;
	int dado[2] = { 0, 1 };

	ll_inicializar(&ll);

	ll_inserir(&ll, NULL, &dado[0]);
	ll_inserir(&ll, NULL, &dado[1]);
	ll_inserir(&ll, NULL, &dado[2]);

	ll_remover(&ll, ll.inicio);
	ll_remover(&ll, ll.inicio);

	ASSERT_NE((struct lld_el*)NULL, ll.inicio);
	ASSERT_NE((struct lld_el*)NULL, ll.fim);
	ASSERT_EQ(ll.inicio, ll.fim);

	ASSERT_EQ(NULL, ll.inicio->ant);
	ASSERT_EQ(NULL, ll.fim->prox);

	ASSERT_EQ(&dado[0], ll.inicio->dado);

	ll_remover(&ll, ll.inicio);
}

TEST(Remover, Lista3ElementosRemoveUltimo)
{
	struct lld ll;
	int dado[3] = { 0, 1, 2 };

	ll_inicializar(&ll);

	ll_inserir(&ll, NULL, &dado[0]);
	ll_inserir(&ll, NULL, &dado[1]);
	ll_inserir(&ll, NULL, &dado[2]);

	ll_remover(&ll, ll.fim);

	ASSERT_NE((struct lld_el*)NULL, ll.inicio);
	ASSERT_NE((struct lld_el*)NULL, ll.fim);
	ASSERT_NE(ll.inicio, ll.fim);

	ASSERT_EQ(NULL, ll.inicio->ant);
	ASSERT_EQ(ll.fim, ll.inicio->prox);
	ASSERT_EQ(ll.inicio, ll.fim->ant);
	ASSERT_EQ(NULL, ll.fim->prox);

	ASSERT_EQ(&dado[2], ll.inicio->dado);
	ASSERT_EQ(&dado[1], ll.inicio->prox->dado);

	ll_remover(&ll, ll.fim);
	ll_remover(&ll, ll.fim);
}

TEST(Remover, Lista3ElementosRemoveUltimoUltimo)
{
	struct lld ll;
	int dado[3] = { 0, 1, 2 };

	ll_inicializar(&ll);

	ll_inserir(&ll, NULL, &dado[0]);
	ll_inserir(&ll, NULL, &dado[1]);
	ll_inserir(&ll, NULL, &dado[2]);

	ll_remover(&ll, ll.fim);
	ll_remover(&ll, ll.fim);

	ASSERT_NE((struct lld_el*)NULL, ll.inicio);
	ASSERT_NE((struct lld_el*)NULL, ll.fim);
	ASSERT_EQ(ll.inicio, ll.fim);

	ASSERT_EQ(NULL, ll.inicio->ant);
	ASSERT_EQ(NULL, ll.fim->prox);

	ASSERT_EQ(&dado[2], ll.inicio->dado);

	ll_remover(&ll, ll.fim);
}

TEST(Remover, Lista3ElementosRemoveMiolo)
{
	struct lld ll;
	int dado[3] = { 0, 1, 2 };

	ll_inicializar(&ll);

	ll_inserir(&ll, NULL, &dado[0]);
	ll_inserir(&ll, ll.fim, &dado[1]);
	ll_inserir(&ll, ll.inicio, &dado[2]);

	ll_remover(&ll, ll.inicio->prox);

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
	ll_remover(&ll, ll.fim);
}
