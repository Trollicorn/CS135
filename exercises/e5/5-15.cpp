//Mohammed Uddin
void sort2(int &a, int &b){
	if (a <= b){
		return;
	}
	int temp = b;
	b = a;
	a = temp;
}

void sort3(int &a, int &b, int &c){
	sort2(a,c);
	sort2(a,b);
	sort2(b,c);
}


