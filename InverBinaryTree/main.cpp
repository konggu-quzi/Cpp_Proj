#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 105


struct TreeNode
{
        int val;
        TreeNode* left;
        TreeNode* right;
};

TreeNode *queue[N];
TreeNode *stack[N];


//创建树
void create_tree(TreeNode *&root)
{
        char c;
        scanf("%c", &c);
        if (c == '0')
        {
                root = NULL;
        }
        else
        {
            root = (TreeNode*)malloc(sizeof(TreeNode));
                root->val = c;
                create_tree(root->left);
                create_tree(root->right);
        }
}


//打印树
void print_tree(TreeNode *root)
{
        if (root != NULL)
        {
                printf("%c", root->val);
                print_tree(root->left);
                print_tree(root->right);
        }
}


//采用递归
void reverse_tree(TreeNode *root)
{
        if (root != NULL)
        {
                TreeNode *s;
                s = root->left;
                root->left = root->right;
                root->right = s;
                reverse_tree(root->left);
                reverse_tree(root->right);
        }
}


//采用队列
void reverse_tree_queue(TreeNode *root)
{
        TreeNode *temp, *p = root;
        int front, rear;
        if (root != NULL)
        {
                queue[0] = root;
                front = -1;
                rear = 0;
                while (front < rear)
                {
                        p = queue[++front];
                        temp = p->left;
                        p->left = p->right;
                        p->right = temp;
                        if (p->left != NULL)
                        {
                                queue[++rear] = p->left;
                        }
                        if (p->right != NULL)
                        {
                                queue[++rear] = p->right;
                        }
                }
        }
}

//采用栈
void reverse_tree_stack(TreeNode *root)
{
        int top = -1;
        TreeNode *p, *bt = root;
        if (root != NULL)
        {
                stack[++top] = root;
                while (top != -1)
                {
                        bt = stack[top--];
                        p = bt->right;
                        bt->right = bt->left;
                        bt->left = p;
                        if (bt->left)
                        {
                                stack[++top] = bt->left;
                        }
                        if (bt->right)
                        {
                                stack[++top] = bt->right;
                        }
                }
        }

}

int main(int argc, char* agrv[])
{
        TreeNode *bt;
        create_tree(bt);
        print_tree(bt);
        printf("\n");
        reverse_tree(bt);
        print_tree(bt);
        printf("\n");

        return 0;
}
