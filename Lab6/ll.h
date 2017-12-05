#pragma once

struct lld_el
{
	void* dado;
	struct lld_el* ant;
	struct lld_el* prox;
};

struct lld
{
	struct lld_el* inicio;
	struct lld_el* fim;
};

void ll_inicializar(struct lld* ll);
void ll_inserir(struct lld* ll, struct lld_el* el, void* eln);
void ll_inserir_antes(struct lld* ll, struct lld_el* el, void* eln);
void ll_remover(struct lld* ll, struct lld_el* el);