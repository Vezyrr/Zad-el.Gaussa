#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
				/* Sprawdzenie poprawnosci rozmiarow macierzy */
				if (!x || !mat || !b) return 2;
				if (mat->r != mat->c) return 2; /* macierz nie jest kwadratowa */
				if (b->c != 1 || x->c != 1) return 2; /* oczekujemy wektorow kolumnowych */
				if (b->r != mat->r || x->r != mat->r) return 2; /* niezgodne rozmiary */

				int n = mat->r;
				int i, j;

				/* Wlasciwe wsteczne podstawienie: U x = b, gdzie U = mat (gorna trojkatna) */
				for (i = n - 1; i >= 0; --i) {
						double diag = mat->data[i][i];
						if (diag == 0.0) return 1; /* blad: dzielenie przez zero */

						double sum = b->data[i][0];
						for (j = i + 1; j < n; ++j) {
								sum -= mat->data[i][j] * x->data[j][0];
						}

						x->data[i][0] = sum / diag;
				}

				return 0;
}


