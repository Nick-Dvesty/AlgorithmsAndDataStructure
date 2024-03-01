using System.Security.Claims;

internal class Program{
    static void Main()
    {
        int[,] test = { { 0, 1},{2,3},{4,5},{6,7},{8,9} };
        int[,] test2 = { { 0, 1,2,3,4,},{5,6,7,8,9} };
        int[,] ans = multiply.multiplyClassic(test, test2);
        //ans = multiply.submatrix((1,1),(2,3),ans);
       //multiply.printMrx(ans);
       int[,] test3 =
       {
           { 1, 2, 3, 4, },
           { 5, 4, 5, 6, },
           { 6, 7, 8, 9, },
           { 6, 7, 8, 9, }
       };
        ans = multiply.multyplyShtrasen(test3, test3);
        
        multiply.printMrx(ans);
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
                        ansmrx[i, j] += mrx1[i,k] * mrx2[k, j];
                    }
                }
            }

            return ansmrx;
        }

        return null;
    }
    static public int[,] multiplyRecurse(int[,] mrx1, int[,] mrx2)
    {
        if ((mrx1.Length > 4) && (mrx2.Length > 4))
        {

            int hight1 = mrx1.GetLength(0);
            int width1 = mrx1.GetLength(1);
            int hight2 = mrx2.GetLength(0);
            int width2 = mrx2.GetLength(1);
            int[,] ansMrx = new int[hight1,width2];
            int[,] a, b, c, d, e, f, g, h;
            a = multiply.submatrix((1, 1), (hight1 / 2, width1 / 2), mrx1);
            b = multiply.submatrix((1, width1 / 2), (hight1 / 2, width1 - width1 / 2), mrx1);
            c = multiply.submatrix((hight1 / 2, 1), (hight1 - hight1 / 2, width1 / 2), mrx1);
            d = multiply.submatrix((hight1 / 2, width1 / 2), (hight1 - hight1 / 2, width1 - width1 / 2), mrx1);

            e = multiply.submatrix((1, 1), (hight2 / 2, width2 / 2), mrx2);
            f = multiply.submatrix((1, width2 / 2), (hight2 / 2, width2 - width2 / 2), mrx2);
            g = multiply.submatrix((hight2 / 2, 1), (hight2 - hight2 / 2, width2 / 2), mrx2);
            h = multiply.submatrix((hight2 / 2, width2 / 2), (hight2 - hight2 / 2, width2 - width2 / 2), mrx2);

            int[,] ae, bg, af, bh, ce, dg, cf, dh;
            
            ae = multiplyRecurse(a, e);
            bg = multiplyRecurse(b, g);
            af = multiplyRecurse(a, f);
            bh = multiplyRecurse(b, h);
            ce = multiplyRecurse(c, e);
            dg = multiplyRecurse(d, g);
            cf = multiplyRecurse(c, f);
            dh = multiplyRecurse(d, h);

            ansMrx = plussubmatrix((1, 1), ae, ansMrx);
            ansMrx =plussubmatrix((1, 1), bg, ansMrx);
            
            ansMrx =plussubmatrix((1, width2 / 2),af,ansMrx);
            ansMrx =plussubmatrix((1, width2 / 2),bh,ansMrx);
            
            ansMrx =plussubmatrix((hight1 / 2, 1),ce,ansMrx);
            ansMrx =plussubmatrix((hight1 / 2, 1),dg,ansMrx);
            
            ansMrx =plussubmatrix((hight1 / 2, width2 / 2),cf,ansMrx);
            ansMrx =plussubmatrix((hight1 / 2, width2 / 2),dh,ansMrx);
            return ansMrx;
        }
        else
        {
            int[,] ans = multiplyClassic(mrx1, mrx2);
            return ans;
        }


    }

    static public int[,] multyplyShtrasen(int[,] mrx1, int[,] mrx2)
    {
            if ((mrx1.Length > 4) && (mrx2.Length > 4))
            {

                int hight1 = mrx1.GetLength(0);
                int width1 = mrx1.GetLength(1);
                int hight2 = mrx2.GetLength(0);
                int width2 = mrx2.GetLength(1);
                int[,] ansMrx = new int[hight1, width2];
                int[,] a, b, c, d, e, f, g, h;
                a = multiply.submatrix((1, 1), (hight1 / 2, width1 / 2), mrx1);
                b = multiply.submatrix((1, width1 / 2), (hight1 / 2, width1 - width1 / 2), mrx1);
                c = multiply.submatrix((hight1 / 2, 1), (hight1 - hight1 / 2, width1 / 2), mrx1);
                d = multiply.submatrix((hight1 / 2, width1 / 2), (hight1 - hight1 / 2, width1 - width1 / 2), mrx1);

                e = multiply.submatrix((1, 1), (hight2 / 2, width2 / 2), mrx2);
                f = multiply.submatrix((0, width2 / 2), (hight2 / 2, width2 - width2 / 2), mrx2);
                g = multiply.submatrix((hight2 / 2, 1), (hight2 - hight2 / 2, width2 / 2), mrx2);
                h = multiply.submatrix((hight2 / 2, width2 / 2), (hight2 - hight2 / 2, width2 - width2 / 2), mrx2);

                int[,] p1, p2, p3, p4, p5, p6, p7;
                p1 = multyplyShtrasen(a, minusmatrix((1, 1),f, h));
                p2 = multyplyShtrasen(plussubmatrix((1, 1), a, b), h);
                p3 = multyplyShtrasen(plussubmatrix((1, 1), c, d), e);
                p4 = multyplyShtrasen(d, minusmatrix((1, 1),g, e));
                p5 = multyplyShtrasen(plussubmatrix((1, 1), a, d), plussubmatrix((1, 1), e, h));
                p6 = multyplyShtrasen(minusmatrix((1, 1), b, d), plussubmatrix((1, 1), g, h));
                p7 = multyplyShtrasen(minusmatrix((1, 1), a, c), plussubmatrix((1, 1), e, f));

                ansMrx= plussubmatrix((1, 1), p5, ansMrx);
                ansMrx= plussubmatrix((1, 1), p4, ansMrx);
                ansMrx= minusmatrix((1, 1), p2, ansMrx);
                ansMrx= plussubmatrix((1, 1), p6, ansMrx);
                
                ansMrx= plussubmatrix((1, width2 / 2), p1, ansMrx);
                ansMrx= plussubmatrix((1, width2 / 2), p2, ansMrx);

                ansMrx= plussubmatrix((hight1 / 2, 1), p3, ansMrx);
                ansMrx= plussubmatrix((hight1 / 2, 1), p4, ansMrx);

                ansMrx= plussubmatrix((hight1 / 2, width2 / 2), p1, ansMrx);
                ansMrx= plussubmatrix((hight1 / 2, width2 / 2), p5, ansMrx);
                ansMrx= minusmatrix((hight1 / 2, width2 / 2), p3, ansMrx);
                ansMrx= minusmatrix((hight1 / 2, width2 / 2), p7, ansMrx);
                return ansMrx;
            }
            else
            {
                int[,] ans = multiplyClassic(mrx1, mrx2);
                return ans;
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
        int[,] ansMrx = new int[mrx.GetLength(0),mrx.GetLength((1))];
        for (int i = 0; i < mrx.GetLength(0); i++)
        {
            for (int j = 0; j < mrx.GetLength(1); j++)
            {
                ansMrx[i, j] = mrx[i, j];
            }
        }
        for (int i = 0; i < submtx.GetLength(0); i++)
        {
            for (int j = 0; j < submtx.GetLength(1); j++)
            {
                ansMrx[i + coordinate.x-1, j + coordinate.y -1] =  mrx[i + coordinate.x -1, j + coordinate.y -1] + submtx[i, j];
            }
        }

        return ansMrx;
    }
    static public int[,] minusmatrix((int x, int y) coordinate, int[,] submtx, int[,] mrx)
    {
        int[,] ansMrx = new int[mrx.GetLength(0),mrx.GetLength((1))];
        for (int i = 0; i < mrx.GetLength(0); i++)
        {
            for (int j = 0; j < mrx.GetLength(1); j++)
            {
                ansMrx[i, j] = mrx[i, j];
            }
        }
        for (int i = 0; i < submtx.GetLength(0); i++)
        {
            for (int j = 0; j < submtx.GetLength(1); j++)
            {
                ansMrx[i + coordinate.x -1, j + coordinate.y -1] =  mrx[i + coordinate.x -1, j + coordinate.y-1] - submtx[i, j];
            }
        }

        return ansMrx;
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