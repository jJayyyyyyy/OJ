#include <iostream>
#define MAX 32
using namespace std;

int preOrder[MAX] = {0};
int postOrder[MAX] = {0};
int inOrder[MAX] = {0};
int ixInOrder = 0;
int unique = 1;

int findRightRoot(const int vRightRoot, const int preLeft, const int preRight){
	// val is root of right child
	for( int ix=preLeft; ix<=preRight; ix++ ){
		if( vRightRoot == preOrder[ix] ){
			return ix;
		}
	}

	return 0;	// right root not found, 
}

int setIn(int preLeft, int preRight, int postLeft, int postRight){
	if( preLeft == preRight){
		inOrder[ixInOrder++] = preOrder[preLeft];
		return 0;
	}

	if( preOrder[preLeft] == postOrder[postRight] ){// get root
		int vRightRoot = postOrder[postRight - 1];
		int ixLeftRoot = preLeft + 1;
		int ixRightRoot = findRightRoot(vRightRoot, preLeft+1, preRight);
		
		int preLeftLeft = preLeft + 1;
		int preLeftRight = ixRightRoot - 1;
		int preRightLeft = ixRightRoot;
		int preRightRight = preRight;

		int cntLeftTree = preLeftRight - preLeftLeft + 1;

		int postLeftLeft = postLeft;
		int postLeftRight = postLeft + cntLeftTree - 1;
		int postRightLeft = postLeft + cntLeftTree;
		int postRightRight = postRight - 1;

		if( ixRightRoot > ixLeftRoot ){
			// suppose the left tree is equal

			// LDR, inOrder
			setIn( preLeftLeft, preLeftRight, postLeftLeft, postLeftRight );
			inOrder[ixInOrder++] = preOrder[preLeft];
			setIn( preRightLeft, preRightRight, postRightLeft, postRightRight );
		}else{
			// ixRightRoot == ixLeftRoot
			// means the left tree is empty
			// yet it's guaranteed there is a tree
			// so the node is on the right tree
			// and the tree is not unique
			unique = 0;
			
			// the first setIn() does nothing, for the left tree is empty
			setIn( preLeftLeft, preLeftRight, postLeftLeft, postLeftRight );
			
			inOrder[ixInOrder++] = preOrder[preLeft];
			setIn( preRightLeft, preRightRight, postRightLeft, postRightRight );
		}
	}
	return 0;
}

int main() {
	int n, i;
	cin>>n;
	for (i=0; i<n; i++) {
		cin>>preOrder[i];
	}

	for (i=0; i<n; i++) {
		cin>>postOrder[i];
	}

	setIn(0, n-1, 0, n-1);
	if( unique ){
		cout<<"Yes\n";
	}else{
		cout<<"No\n";
	}
	
	cout<<inOrder[0];
	for (i=1; i<n; i++) {
		cout<<' '<<inOrder[i];
	}
	cout<<'\n';
	return 0;
}
