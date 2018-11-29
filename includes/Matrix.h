
void initializeMatrix(double **m, int numOfRows, int numOfColumns);

void MatrixMultiplication(double **A, int order, double **B, double **result);

void MatrixInversion(double **A, int order, double **Y);

void MatrixTranspose(double **matrix, double **result, int n, int m);

int GetMinor(double **src, double **dest, int row, int col, int order);

double CalcDeterminant(double **mat, int order);
