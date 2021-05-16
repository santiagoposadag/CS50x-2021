#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;

//I created my own method to capture in a more explicit way a number;
int get_int(char *output);

//this method helps us by recursion to add a number properly in a sorted maner
int add_to_tree(int number, node *tree);

//to check everything that we have added.
int print_tree(node *tree);

//As we have used malloc and we dont want memory leaks we have to free the memory;
int free_memory(node *tree);

int main(void)
{
    node *tree = NULL;

    node *n = malloc(sizeof(node));

    if (n == NULL)
    {
        return 1;
    }

    n->number = get_int("insert the number that you want to save: ");
    n->left = NULL;
    n->right = NULL;

    tree = n;

    node *tmp = NULL;

    int answer = get_int("Do you want to keep adding numbers?\n if yes answer 1 or if not answer 2 ");

    while (answer == 1)
    {
        int number = get_int("What is the number that you want to add? ");
        add_to_tree(number, tree);
        answer = get_int("Do you want to keep adding numbers?\nif yes answer 1 or if not answer 2 ");
    }
        if (answer == 2)
    {
        print_tree(tree);
        free_memory(tree);
        return 0;
    }



}

int get_int(char *output)
{
    int number;
    printf("%s", output);
    scanf("%i", &number);
    return number;
}



int add_to_tree(int number, node *tree)
{
    node *tmp_left = NULL;
    node *tmp_right = NULL;
    if (tree == NULL)
    {
        return 1;
    }

    if (number == tree->number)
    {
        return 0;
    }
    else if (tree->left == NULL && number < tree->number)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = number;
        n->left = NULL;
        n->right = NULL;

        tree->left = n;
        return 0;
    }
    else if(tree->left != NULL && number < tree->number)
    {
        tmp_left = tree->left;
        add_to_tree(number, tmp_left);
        return 0;
    }
    else if (tree->right == NULL && number > tree->number)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = number;
        n->left = NULL;
        n->right = NULL;

        tree->right = n;
        return 0;
    }
    else if (tree->right != NULL && number > tree->number)
    {
        tmp_right = tree->right;
        add_to_tree(number, tmp_right);
        return 0;
    }
    return 1;
}

int print_tree(node *tree)
{
    node *tmp_left = NULL;
    node *tmp_right = NULL;
    if (tree == NULL)
    {
        return 1;
    }

    if (tree->left != NULL && tree->right != NULL )
    {
        printf("%i\n", tree->number);
        tmp_left = tree->left;
        tmp_right = tree->right;
        print_tree(tmp_left);
        print_tree(tmp_right);
        return 0;
    }
    else if(tree->left != NULL)
    {
        printf("%i\n", tree->number);
        tmp_left = tree->left;
        print_tree(tmp_left);
        return 0;
    }
    else if (tree->right != NULL)
    {
        printf("%i\n", tree->number);
        tmp_right = tree->right;
        print_tree(tmp_right);
        return 0;
    }
    else if (tree->left == NULL && tree->right == NULL)
    {
        printf("%i\n", tree->number);
        return 0;
    }
    return 1;
}

int free_memory(node *tree)
{
    node *tmp_left = NULL;
    node *tmp_right = NULL;
    if (tree == NULL)
    {
        return 1;
    }

    if (tree->left != NULL && tree->right != NULL )
    {
        tmp_left = tree->left;
        tmp_right = tree->right;
        free(tree);
        free_memory(tmp_left);
        free_memory(tmp_right);
        return 0;
    }
    else if(tree->left != NULL)
    {
        tmp_left = tree->left;
        free(tree->left);
        free_memory(tmp_left);
        return 0;
    }
    else if (tree->right != NULL)
    {
        tmp_right = tree->right;
        free(tree->right);
        free_memory(tmp_right);
        return 0;
    }
    return 1;
}