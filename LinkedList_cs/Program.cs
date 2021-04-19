using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LinkedList
{
    class Program
    {
        static void Main(string[] args)
        {
            LL<int> list = new LL<int>();
            for(int i = 0; i< 10; i++)
            {
                list.addLast(i);
            }
            list.addidx(idx: 2, datum: 99);

            Console.WriteLine(list.ToString());
            Console.WriteLine(list.Reverse());
        }
    }
}
