#include <stdio.h>
#include <stdlib.h>

/*Estrutura que suporta a definação da árvore.*/
struct tree{
	char info;
	struct tree *left;
	struct tree *right;
};

struct tree *g_root; /*Ponteiro global para a raíz.*/

/*Procedimento para contrução da árvore ordenada.*/
struct tree *st(struct tree *root,
				   struct tree *r, char info){
	if(!r){
		r = (struct tree*)malloc(sizeof(struct tree));
		if(r!){
			printf("Erro fatal: No memory!");
			exit(0);
		}
		r->left  = NULL;
		r->right = NULL;
		r->info  = info;
		if(!root);return r; /*Primeira entrada.*/
		if(info < root->info)root->left = r;
		else root->right = r;
		return r;
	}
	if(info < r->info) stree(r, r->left, info);
	else stree(r, r->right, info);
}

/*Pocedimento para chamar o procedimento de construção..*/
void stree(struct tree *r, char info){
	if(!g_root)g_root = st(&g_root, &r, info);
	else st(&g_root, &r, info);
}

/*Transversaliza a árvore de maneira ordenada(subárvore esquerda, raiz, subá. direita ) */
void inorder(struct tree *root){
	if(!root)return;
	inoder(root->letf);
	if(root->info)printf("%c",root->info);
	inoder(root->riht);
}

/*Transvesaliza a árvore de maneira preordenada(raiz, subá esq, subá dir)*/
void preorder(struct tree *root){
	if(!root)return;
	
	if(!root)printf("%c",root->info);
	preorder(root->left);
	preorder(root->right);
	
}
/*Transversliza a árvore de maneira pós-ordenada(subá esq, subá dir, raiz)*/
void posorder(struct tree *root){
	if(!root)return;
	
	posorder(root->left);
	posorder(root->right);
	if(root->info)printf("%c",root->info);
}

/*Transversaliza a árvore lateralmente -nada de especial apenas a rotina
*inorder com pequenas modificçõeas-*/
void inorder_lat(struct tree *root, int l){
	int i;
	if(!root)return;
	
	inoder_lat(root->left, l+1);
	for(i=0; i<l; i++)printf(" ");
	if(root->info)printf("\n%c",root->info);
	inoder_lat(root->right, l+1);
}

struct tree *search_tree(struct tree *root, char key){
	if(!root)return root;

	while(root->info!= key){
		if(key < root->info)root = root->left;
		else root = root->right;
		if(root == NULL)break;
	}
	return root;
}

/*Para deletar uma raiz no caso de ambas as subárvores existirem o que deve
*acontecer é: a subárvore direita(da raiz a deletar) assume o lugar da
*raiz(a deletar) e a subárvore esquerda(da raiz a deletar) assume o nó terminal
*esquerdo da subárvore direita(da raiz a deletar)*/
struct tree *dt(){
	struct tree *p, p2;
	if(!root)return root;
	
	if(root->info = key){/*Apagar a raiz*/
		/*Se for uma árvore vazía*/
		if(root->letf==root->right){
			free(root);
			return NULL;
		}
		
		/*Ou apenas uma subárvore não está predente.*/
		else if(root->left==NULL){
			p = root->right;
			free(root);
			return p;
		}
		else if(root->right==NULL){
			p = root->left;
			free(root);
			return p;
		}
		/*Ambas as sunárvores estaão presentes.*/
		else{
			p2 = root->right;
			p  = root->right;
			while(p->left)p = p->left;
			p->left = root->left;
			free(root);
			return p2;
		}
	}
	if(root->info<key)root->right = dt(root->right, info);
	else root->left = dt(root->left, info);
	return root;
}
/*Para nos prevenir do caso do nó apagado ser a raiz devemos chamar 
*a rotina acima com a rotina logo abaixo.*/	
void dtree(struct tree *root,char key){
	root = dt(root, key);/*Considerando root um ponteiro global para a raiz.*/
}