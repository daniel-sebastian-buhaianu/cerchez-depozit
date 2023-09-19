#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned short n, i, *rest, c, k;
	unsigned s;

	FILE *fin = fopen("depozit.in", "r");

	if (!fin) { printf("Eroare fisier depozit.in\n"); return 1; }

	fscanf(fin, "%hu", &n);

	rest = (unsigned short*)calloc(n, sizeof(unsigned short*));

	if (!rest) { printf("Eroare alocare memorie *rest\n"); return 2; }

	FILE *fout = fopen("depozit.out", "w");

	for (s = 0, i = 1; i <= n; i++) {
		fscanf(fin, "%hu", &c);

		s += c;

		if (s % n == 0) {
			for (k = 1; k <= i; k++) fprintf(fout, "%hu ", k);

			return 0;
		}

		if (rest[s % n]) {
			for (k = rest[s % n] + 1; k <= i; k++) fprintf(fout, "%hu ", k);

			return 0;
		}

		rest[s % n] = i;
	}

	fprintf(fout, "Nu exista solutie");

	fclose(fout);
	fclose(fin);

	free(rest);

	return 0;
}

