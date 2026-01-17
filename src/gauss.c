#include "gauss.h"
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
/*
int znajdz_element_glowny_w_kol(Matrix* mat, int nr_kolumny)
{
	int od_ktorego_elementu_w_dol_szukamy = nr_kolumny;
	for(int i = od_ktorego_elementu_w_dol_szukamy; i < mat->c; i++)
	{
		
	}
}
*/
int eliminate(Matrix *mat, Matrix *b)
{
	printf("\n\n");
	printf("\n\n");
    

	for(int kol = 0; kol < mat->c; kol++)
	{
		
//szukamy rzędu z el głównym (najwiekszy co do modułu od diagonalnego w dół)
		double max_abs_w_rzedzie = 0.0;
		int idx_rzedu_z_max = kol;
		for (int rzad = kol; rzad < mat->r; rzad++) {
			if (fabs(mat->data[rzad][kol]) > max_abs_w_rzedzie) {
				idx_rzedu_z_max = rzad;
				max_abs_w_rzedzie = fabs(mat->data[rzad][kol]);
			}
		}
		

		// jesli maksymalny element jest zerowy -> macierz osobliwa
		if (max_abs_w_rzedzie == 0.0) {
			return 1; /* macierz osobliwa */
		}
//zmiana do wywołania konfliktu na test

		// zamieniamy wiersze macierzy A (mat) tak, aby element glowny byl na gorze
		if (idx_rzedu_z_max != kol) {
			double *tmp_row = (double*) malloc(sizeof(double) * mat->c);
			for (int i = 0; i < mat->c; ++i) tmp_row[i] = mat->data[idx_rzedu_z_max][i];
			for (int i = 0; i < mat->c; ++i) mat->data[idx_rzedu_z_max][i] = mat->data[kol][i];
			for (int i = 0; i < mat->c; ++i) mat->data[kol][i] = tmp_row[i];
			free(tmp_row);

			// zamiana odpowiadajacych wierszy wektora b (kolumna)
			double b_tmp = b->data[kol][0];
			b->data[kol][0] = b->data[idx_rzedu_z_max][0];
			b->data[idx_rzedu_z_max][0] = b_tmp;
		}

		// dokonujemy zerowania obecnej kolumny
		if (kol != mat->c - 1) {
			for (int rzad = kol + 1; rzad < mat->r; rzad++) {
				double factor = mat->data[rzad][kol] / mat->data[kol][kol];
				/* aktualizujemy tylko kolumny od 'kol' do konca */
				for (int kol_temp = kol; kol_temp < mat->c; kol_temp++) {
					mat->data[rzad][kol_temp] -= mat->data[kol][kol_temp] * factor;
				}
				/* aktualizujemy wektor b (kolumna) raz dla tego rzedu */
				b->data[rzad][0] -= b->data[kol][0] * factor;
			}
		}
		//printToScreen(mat);

	}

	printf("\n\n");
	printToScreen(mat);
	printToScreen(b);
	
	return 0;

}

