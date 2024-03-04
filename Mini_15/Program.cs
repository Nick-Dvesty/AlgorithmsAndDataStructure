// See https://aka.ms/new-console-template for more information

using System.Drawing;

class Program
{
    static void Main()
    {
        //Пример работы Динамического массива
        DinamicArray<int> test = new DinamicArray<int>();
        test.Add(12);
        test.Add(5);
        test.Add(7);
        test.Add(786);
        test.Remove();
        test.Remove();
        test.Remove();
        int y = test[1];
        test[1] = 78;
    }
}

class  DinamicArray<T>
{
    private T[] _Array;
    private UInt32 _Length;

    public DinamicArray(UInt32 size = 1)
    {
        _Array= new T[size];
        _Length = size;
    }
    
    public void Add(T element){
        if (_Array.Length == _Length){
            T[] newArray = new T[_Array.Length * 2];
            CopyArray(ref _Array, ref newArray, _Array.Length);
            _Array = newArray;
        }
        _Array[_Length++] = element;
    }
    
    public void Remove()
    {
        _Length--;
        if (_Length * 4 <= _Array.Length){
            T[] newArray = new T[_Array.Length /2];
            CopyArray(ref _Array, ref newArray, _Array.Length / 2);
            _Array = newArray;
        }
    }

    public ref T this[int index]
    {
        get
        {
                if (index < _Length){
                    return ref _Array[index];    
                }
                else
                {
                    throw new ArgumentOutOfRangeException();
                }
        }
    } 

    private void CopyArray(ref T[] oldArray, ref T[] newArray, int size){
        for (int i = 0; i < size; i++)
        {
            newArray[i] = oldArray[i];
        }
    }
        
}