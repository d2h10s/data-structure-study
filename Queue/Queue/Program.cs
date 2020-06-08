using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Queue
{
    class Program
    {
        static void Main(string[] args)
        {
            //Queue<int> tt = new Queue<int>();
            //for(int i = 0; i< 10; i++)
            //    tt.enqueueu(i);
            //for (int i = 0; i < 11; i++)
            //    tt.dequeue();
            //Console.WriteLine(tt);
            //Console.WriteLine(tt.size);

            Stack<int> tt = new Stack<int>();
            for (int i = 0; i < 10; i++)
            {
                tt.push(i);
                Console.WriteLine(tt);
            }
                
            for (int i = 0; i < 11; i++)
            {
                tt.pop();
                Console.WriteLine(tt);
            }
            Console.ReadKey();
        }
    }
}
