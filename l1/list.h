#ifndef _list_h_
#define _list_h_
/*
 * 2016, Sebastian Mountaniol.
 * Helen OS project
 * Implementation of one disrectional and bi-directional lists.
 */

struct list {
	struct list *n;
	void *data;
};
typedef struct list list_t;

struct dlist {
	struct dlist *n;
	struct dlist *p;
	void *data;
};
typedef struct dlist dlist_t;


/* Not atomic, must be protected by user */
inline void list_add(list_t *a, list_t *b) {
	b->n = a->n;
	a->n = b;
}

/* Not atomic, must be protected by user */
inline void list_del(list_t *a, list_t *b) {
	a->n = b->n;
}

/* Not atomic, must be protected by user */
inline void dlist_add(list_t *a, list_t *b) {
	b->n = a->n;
	a->n = b;
	b->p = a;
}

/* Not atomic, must be protected by user */
inline void dlist_del(list_t *a, list_t *b) {
}

#endif /* _list_h_ */
