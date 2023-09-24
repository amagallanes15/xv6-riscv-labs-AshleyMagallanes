   Multiply Matrices
    (SQUARE)
  */
  for (i=0; i<ROWS; i++) {
    for (j=0; j<COLUMNS; j++) {
      for (k=0; k<COLUMNS; k++) {
        c[i][j] += a[i][k]*b[k][j];
      }
    }
  }

  /* PRINT RESULT */
  if (ROWS<10)
  {
    for (i=0; i<ROWS; i++) {
      for (j=0; j<COLUMNS; j++) {
        printf("%p ", c[i][j]);
      }
      printf("\n");
    }
  }
  }
  /* Stop Timing */
  int end_time = uptime();

  /* Report Time */
  printf("Time: %d ticks\n", end_time - start_time);

  exit(0);
}
