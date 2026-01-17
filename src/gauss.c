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
    /**
  	 * Tutaj należy umieścić właściwą implemntację.
		 */

	for(int kol = 0; kol < mat->c; kol++)
	{
		
		//szukamy rzędu z el głównym
		double max_abs_w_rzedzie = 0;
		int idx_rzedu_z_max = kol; 
		for(int rzad = kol; rzad < mat->r; rzad++)
		{
			if(fabs(mat->data[rzad][kol]) > max_abs_w_rzedzie)
			{
				idx_rzedu_z_max = rzad;
				max_abs_w_rzedzie = fabs(mat->data[rzad][kol]);
			}
		}
	//zamieniamy w b
		double b_holder;
		b_holder = b->data[0][idx_rzedu_z_max];
		b->data[0][idx_rzedu_z_max] = b->data[0][kol];
		b->data[0][kol] = b_holder;	
	
		
	//zamieniamy, by el glowny był "na górze"
		double row_temp_holder[mat->c];
		//kopiujemy gorny rzad do tymczasowej zmiennej
		for(int kol_temp = 0; kol_temp < mat->c; kol_temp++)
		{
			row_temp_holder[kol_temp] = mat->data[idx_rzedu_z_max][kol_temp];
			//printf("%d: %f \n", kol_temp, mat->data[idx_rzedu_z_max][kol_temp]);
		}
		for(int kol_temp = 0; kol_temp < mat->c; kol_temp++)
		{
			mat->data[idx_rzedu_z_max][kol_temp] = mat->data[kol][kol_temp];
		}
		for(int kol_temp = 0; kol_temp < mat->c; kol_temp++)
		{
			mat->data[kol][kol_temp] = row_temp_holder[kol_temp];
		}
		
		//printToScreen(mat);
		//printf("test\n");

	//dokonujemy zerowania obecnej kolumny
		if(kol != mat->c - 1)
		{
			for(int rzad = kol + 1; rzad < mat->r; rzad++)
			{
				double jaka_czesc_rzedu_gluwnego_odejmujemy = mat->data[rzad][kol] / mat->data[kol][kol];
				for(int kol_temp = 0; kol_temp < mat->c; kol_temp++)
				{
					mat->data[rzad][kol_temp] = mat->data[rzad][kol_temp] - mat->data[kol][kol_temp] * jaka_czesc_rzedu_gluwnego_odejmujemy;
					
					
				}
				b->data[0][rzad] = b->data[0][rzad] - b->data[0][kol] * jaka_czesc_rzedu_gluwnego_odejmujemy;
			}
		}
		//printToScreen(mat);

	}

	printf("\n\n");
	printToScreen(mat);
	printToScreen(b);
	
	return 0;
}

//komentarz do bledu
