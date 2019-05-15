/*
Nama Program		: Exercise-02
Nama				: Prayudha Adhitia Libramawan
NPM					: 140810180008
Tanggal Pembuatan	: 15 05 2019
Deskripsi			: Tree Exercise
*/
#include<iostream>
using namespace std;

struct simpul{
    int info;
    simpul* left;
    simpul* right;
};

typedef simpul* pointer;
typedef pointer tree;

void createSimpul(pointer& pBaru);
void insertBST(tree& root, pointer pBaru);
void preOrder(tree root);
void inOrder(tree root);
void postOrder(tree root);
int height(tree Root);
void givenLevel(tree Root, int level);
void depthOrder(tree Root);
void levelOrder(tree Root);
void printChildren(tree Root, pointer pBaru);

int main(){
    tree Root=NULL;
    pointer p;
    int opt, n;
    char loop;

    cout<<"\n---------------TREE---------------"<<endl;
    cout<<"Masukkan banyak Node : "; //15
    cin>>n; 
    for (int i=0;i<n;i++){
        // 7  11  3  4  5  9  12  15  1  10  2  25  8  14  19
        
        createSimpul(p);
        insertBST(Root,p);
    }
    do{
        system("cls");
        cout<<"---------------MENU---------------"<<endl;
        cout<<"1. InsertBST"<<endl;
        cout<<"2. PreOrder"<<endl;
        cout<<"3. InOrder"<<endl;
        cout<<"4. PostOrder"<<endl;
        cout<<"5. Kedalaman"<<endl;
        cout<<"6. Level"<<endl;
        cout<<"7. Anak"<<endl;
        cout<<"8. Exit"<<endl;
        cout<<"\nPILIHAN : ";cin>>opt;

        switch(opt){
            case 1:
                cout<<"INSERT BST"<<endl;
                createSimpul(p);
                insertBST(Root,p);
                break;

            case 2:
                cout<<"TRAVERSAL PREORDER"<<endl;
                preOrder(Root);
                break;
                
            case 3:
                cout<<"TRAVERSAL INORDER"<<endl;
                inOrder(Root);
                break;
                
            case 4:
                cout<<"TRAVERSAL POSTORDER"<<endl;
                postOrder(Root);
                break;

            case 5:
                cout<<"KEDALAMAN"<<endl;
                depthOrder(Root);
                break;
            
            case 6:
                cout<<"LEVEL"<<endl;
                levelOrder(Root);
                break;

            case 7:
                cout<<"ANAK"<<endl;
                printChildren(Root, p);
                break;

            case 8:
                cout<<"\nTerima Kasih !"<<endl;
                return 0;
                break;
            default:
            cout<<"Pilihan anda salah"<<endl;
            break;
        }
        cout<<"\n\nKembali ke menu [Y/N]? "; cin>>loop;
    }while(loop=='y'|| loop=='Y');
    cout<<"Terima Kasih !"<<endl;
}

void createSimpul(pointer& pBaru) {
    pBaru = new simpul;
    cout << "Masukkan angka : ";
    cin >> pBaru->info;
    pBaru->left = NULL;
    pBaru->right = NULL;
}

void insertBST(tree& root, pointer pBaru){
    if (root==NULL)
        root=pBaru;
    else if(pBaru->info < root->info)
        insertBST(root->left, pBaru);
    else if(pBaru->info >= root->info)
        insertBST(root->right, pBaru);
    else
        cout<<"sudah ada";
}

void preOrder(tree root){
    if(root!=NULL){
        cout<<root->info<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(tree root){
    if(root!=NULL){
        inOrder(root->left);
        cout<<root->info<<" ";
        inOrder(root->right);
    }
}

void postOrder(tree root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->info<<" ";   
    }
}

int height(tree Root){
    if (Root==NULL) return 0;
    else{
        int lHeight=height(Root->left);
        int rHeight=height(Root->right);

        if (lHeight>rHeight) return (lHeight+1);
        else return (rHeight+1);
    }
}


void givenLevel(tree Root, int level){
    if (Root==NULL) 
        return;
    if (level==1) 
        cout << Root->info << " ";
    else if (level>1){
        givenLevel(Root->left,level-1);
        givenLevel(Root->right,level-1);
    }
}

void depthOrder(tree Root){
    int h=height(Root);
    for (int i=1; i<=h; i++){
        cout << i-1 << ": " <<" [ ";
        givenLevel(Root,i);
        cout<< "]"<< endl;
    }
}

void levelOrder(tree Root){
    int h=height(Root);
    for (int i=1; i<=h; i++){
        cout << i << ": " <<" [ ";
        givenLevel(Root,i);
        cout<< "]"<< endl;
    }
}

void printChildren(tree Root, pointer pBaru){
    pBaru= Root;
    if(pBaru!=NULL){
        cout<<"Parent Node = "<<pBaru->info<<endl;

        if(pBaru->left == NULL)
            cout<<"Left Child = NULL"<<endl;
        else
            cout<<"Left Child = "<<pBaru->left->info<<endl;
                     
        if(pBaru->right == NULL)
            cout<<"Right Child = NULL"<<endl;
        else
            cout<<"Right Child = "<<pBaru->right->info<<endl;

        cout<<endl;    

        printChildren(Root->left, pBaru);
        printChildren(Root->right, pBaru);
    }
}