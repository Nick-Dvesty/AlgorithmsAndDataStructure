using System.Security.Claims;

internal class Program{
    static void Main()
    {
        int[,] test = { { 0, 1},{2,3},{4,5},{6,7},{8,9} };
        int[,] test2 = { { 0, 1,2,3,4,},{5,6,7,8,9} };
        int[,] ans = multiply.multiplyClassic(test, test2);
        ans = multiply.submatrix((1,1),(2,3),ans);
       // multiply.printMrx(ans);
        int[,] test3 = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
        multiply.multiplyRecurse(test3, test3);
    }
}

class multiply{
    static public int[,] multiplyClassic(int[,] mrx1, int[,] mrx2)
    {
        if (mrx1.GetLength(1) == mrx2.GetLength(0))
        {
            int[,] ansmrx = new int[mrx1.GetLength(0), mrx2.GetLength(1)];
            for (int i = 0;  i < mrx1.GetLength(0); i++)
            {
                for (int j = 0; j < mrx2.GetLength(1); j++)
                {
                    for (int k = 0; k < mrx1.GetLength(1); k++)
                    {
                        ansmrx[j, i] += mrx1[j,k] * mrx2[k, i];
                    }
                }
            }

            return ansmrx;
        }

        return null;
    }

    static public void multiplyRecurse(int[,] mrx1, int[,] mrx2)
    {
        if ((mrx1.Length > 1) || (mrx2.Length > 1))
        {
            int hight1 = mrx1.GetLength(0);
            int width1 = mrx1.GetLength(1);
            int hight2 = mrx2.GetLength(0);
            int width2 = mrx2.GetLength(1);
            int[,] a, b, c, d, e, f, g, h;
            a = multiply.submatrix((0, 0), (hight1 / 2, width1 / 2), mrx1);
            b = multiply.submatrix((0, width1 / 2), (hight1 / 2, width1 - width1 / 2), mrx1);
            c = multiply.submatrix((hight1 / 2, 0), (hight1 - hight1 / 2, width1 / 2), mrx1);
            d = multiply.submatrix((hight1 / 2, width1 / 2), (hight1 - hight1 / 2, width1 - width1 / 2), mrx1);

            e = multiply.submatrix((0, 0), (hight2 / 2, width2 / 2), mrx2);
            f = multiply.submatrix((0, width2 / 2), (hight2 / 2, width2 - width2 / 2), mrx2);
            g = multiply.submatrix((hight2 / 2, 0), (hight2 - hight2 / 2, width2 / 2), mrx2);
            h = multiply.submatrix((hight2 / 2, width2 / 2), (hight2 - hight2 / 2, width2 - width2 / 2), mrx2);

            int[,] ae, bg, af, bh, ce, dg, cf, dh;
            ae = multiplyClassic(a, e);
            bg = multiplyClassic(b, g);
            af = multiplyClassic(a, f);
            bh = multiplyClassic(b, h);
            ce = multiplyClassic(c, e);
            dg = multiplyClassic(d, g);
            cf = multiplyClassic(c, f);
            dh = multiplyClassic(d, h);

        }
        else
        {
            int[,] ans = { { 1 } };
            //return ans;
        }


    }

    static public int[,] submatrix((int x, int y) coordinate, (int height, int width) size, int[,] mrx)
    {
        int[,] ans = new int[size.height, size.width];
        for (int i = 0; i < size.height; i++)
        {
            for (int j = 0; j < size.width; j++)
            {
                ans[i, j] = mrx[coordinate.x+ i, coordinate.y+ j];
            }
        }

        return ans;
    }
    static public int[,] plussubmatrix((int x, int y) coordinate, int[,] submtx, int[,] mrx)
    {
        for (int i = 0; i < submtx.GetLength(0); i++)
        {
            for (int j = 0; j < submtx.GetLength(1); j++)
            {
                mrx[i + coordinate.x, j + coordinate.y] = submtx[i, j];
            }
        }

        return mrx;
    }
    static public void printMrx(int[,] mrx)
    {
        for (int i = 0; i <mrx.GetLength(0); i++)
        {
            for (int j = 0; j < mrx.GetLength(1); j++)
            {
                Console.Write(mrx[i,j] + " ");
            }
            Console.WriteLine();
        }
        Console.WriteLine();
    }
}