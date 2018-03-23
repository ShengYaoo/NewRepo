using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace xmlRead
{
    class PharmaceuticalFactory
     {
        public string type { get; set; }
        public string name { get; set; }
        public string address { get; set; }
        public string formulation { get; set; }
        public string approved_items { get; set; }
        public string GMP { get; set; }
        public string GDP { get; set; }
        public string note { get; set; }
    }
    class Program
    {
        static void Main(string[] args)
        {
            XElement element = XElement.Load("data.xml");
            List<PharmaceuticalFactory> list = new List<PharmaceuticalFactory>();
            element.Descendants("row").ToList().ForEach(row =>
          {
              PharmaceuticalFactory PF = new PharmaceuticalFactory();
              PF.type = row.Element("Col1").Value;
              PF.name = row.Element("Col2").Value;
              PF.address = row.Element("Col3").Value;
              PF.formulation  = row.Element("Col4").Value;
              PF.approved_items  = row.Element("Col5").Value;
              PF.GMP  = row.Element("Col6").Value;
              PF.GDP = row.Element("Col7").Value;
              PF.note = row.Element("Col8").Value;
              list.Add(PF);
          });
            list.ForEach(PF => {
                Console.WriteLine("類別:{0}\n" +
                    "名稱:{1}\n" +
                    "地址:{2}\n" +
                    "核准類型:{3}\n" +
                    "核定品項:{4}\n" +
                    "GMP核定作業內容:{5}\n" +
                    "GDP核定內容:{6}\n" +
                    "備註:{7}\n", PF.type, PF.name, PF.address, PF.formulation, PF.approved_items, PF.GMP, PF.GDP, PF.note);
            });
            Console.ReadKey();
        }
    }
}
