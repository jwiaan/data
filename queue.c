#include <stdio.h>
#include <stdlib.h>

struct task {
	struct task *next;
	int i;
};

struct list {
	struct task *head, **tail;
};

void push(struct list *l, struct task *t)
{
	*l->tail = t;
	l->tail = &t->next;
	t->next = l->head;
}

void print(const struct list *l)
{
	struct task *t = l->head;
	do {
		printf("%d ", t->i);
		t = t->next;
	} while (t != l->head);
	printf("\n");
}

int main(void)
{
	struct list l = { NULL, &l.head };
	for (int i = 0; i < 3; ++i) {
		struct task *t = malloc(sizeof(struct task));
		t->i = i;
		push(&l, t);
		print(&l);
	}
}
