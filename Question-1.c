#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
    int area=0,ar[n];
    int p;
    for(int i=0; i<n; i++){
        p = (tr[i].a+tr[i].b+tr[i].c)/2;
        area = sqrt(p*(p-tr[i].a)*(p-tr[i].b)*(p-tr[i].c));
        ar[i]=area;
    }
    int temp=0;
    for(int i=0; i<n; i++){
        if(ar[i]>ar[i+1]){
            temp=ar[i];
            ar[i]=ar[i+1];
            ar[i+1]=temp;
        }
    }
}


int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle {
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

// Function to calculate the area of a triangle using Heron's formula
double calculate_area(triangle t) {
    int p = (t.a + t.b + t.c) / 2;
    return sqrt(p * (p - t.a) * (p - t.b) * (p - t.c));
}

// Function to compare two triangles by their areas
int compare_triangles(const void *a, const void *b) {
    double area_a = calculate_area(*(triangle *)a);
    double area_b = calculate_area(*(triangle *)b);
    if (area_a < area_b) {
        return -1;
    } else if (area_a > area_b) {
        return 1;
    } else {
        return 0;
    }
}

void sort_by_area(triangle* tr, int n) {
    qsort(tr, n, sizeof(triangle), compare_triangles);
}

int main() {
    int n;
    scanf("%d", &n);
    triangle *tr = malloc(n * sizeof(triangle));
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
    }
    sort_by_area(tr, n);
    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
    }
    return 0;
}