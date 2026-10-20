// ZÁKLADNÍ KONSTRUKCE C#
// Použij jako Program.cs v konzolovém projektu C#.
// Příkazy ukončujeme středníkem ; a bloky vymezujeme závorkami { }.
// Toto je jednořádkový komentář.
/* Toto je
   víceřádkový komentář. */

using System; // Zpřístupní například třídu Console.

// Jmenný prostor seskupuje související třídy.
namespace ZakladyCSharp
{
    class Program
    {
        // Main je vstupní bod programu.
        // static: není potřeba vytvořit objekt třídy Program.
        // void: metoda nevrací hodnotu.
        static void Main()
        {
            // 1. PROMĚNNÉ A TYPY
            int vek = 20;           // Celé číslo.
            double vyska = 1.75;    // Desetinné číslo.
            decimal cena = 99.90m;  // Desetinný typ vhodný například pro peníze.
            char znak = 'A';        // Jeden znak.
            string jmeno = "Jan";   // Text.
            bool student = true;   // Logická hodnota true nebo false.
            var mesto = "Opava";    // Typ string odvodí překladač.
            const int DniVTydnu = 7; // Konstantu nelze později změnit.
            vek = 21;              // Přiřazení nové hodnoty proměnné.

            // 2. VÝSTUP
            Console.Write("Jmeno: "); // Bez přechodu na nový řádek.
            Console.WriteLine(jmeno); // S přechodem na nový řádek.
            // Znak $ umožní vložit hodnoty do textu pomocí { }.
            Console.WriteLine($"Vek: {vek}, vyska: {vyska}, cena: {cena}");
            Console.WriteLine($"Znak: {znak}, student: {student}");
            Console.WriteLine($"Mesto: {mesto}, dni v tydnu: {DniVTydnu}");

            // 3. VSTUP
            Console.Write("Zadej jmeno: ");
            // ReadLine načte řádek. Pokud vrátí null (konec vstupu),
            // operátor ?? použije náhradní prázdný text.
            string zadaneJmeno = Console.ReadLine() ?? "";
            Console.WriteLine($"Ahoj, {zadaneJmeno}!");

            Console.Write("Zadej cele cislo: ");
            int zadaneCislo;
            // TryParse vrací úspěch převodu textu na číslo.
            // out předá výsledek do proměnné zadaneCislo.
            if (int.TryParse(Console.ReadLine(), out zadaneCislo))
            {
                Console.WriteLine($"Zadano: {zadaneCislo}");
            }
            else
            {
                Console.WriteLine("Neplatne cele cislo.");
            }

            // 4. OPERÁTORY
            int a = 7;
            int b = 2;
            Console.WriteLine($"Soucet: {a + b}");
            Console.WriteLine($"Rozdil: {a - b}");
            Console.WriteLine($"Soucin: {a * b}");
            Console.WriteLine($"Celociselne deleni: {a / b}"); // 3
            Console.WriteLine($"Desetinne deleni: {(double)a / b}"); // 3,5
            Console.WriteLine($"Zbytek po deleni: {a % b}"); // 1
            // (double)a převede hodnotu na double pro desetinné dělení.

            // 5. PODMÍNKY
            // == rovnost, != nerovnost, <, >, <=, >= porovnání.
            // Pozor: = přiřazuje, zatímco == porovnává.
            if (vek < 18)
            {
                Console.WriteLine("Mene nez 18 let.");
            }
            else if (vek == 18)
            {
                Console.WriteLine("Presne 18 let.");
            }
            else
            {
                Console.WriteLine("Vice nez 18 let.");
            }

            // && znamená zároveň, || nebo, ! negaci.
            if (vek >= 18 && student)
            {
                Console.WriteLine("Dospely student.");
            }
            if (vek < 18 || student)
            {
                Console.WriteLine("Mladsi nez 18 nebo student.");
            }
            if (!student)
            {
                Console.WriteLine("Neni student.");
            }

            // 6. SWITCH - výběr větve podle hodnoty.
            int volba = 2;
            switch (volba)
            {
                case 1:
                    Console.WriteLine("Prvni moznost.");
                    break;
                case 2:
                    Console.WriteLine("Druha moznost.");
                    break;
                default:
                    Console.WriteLine("Neznama moznost.");
                    break;
            }

            // 7. FOR - inicializace; podmínka; změna po průchodu.
            for (int i = 0; i < 5; i++)
            {
                Console.WriteLine($"for: {i}"); // 0 až 4
            }
            // i++ zvýší hodnotu o 1; i-- ji sníží o 1.

            // 8. WHILE - podmínka se ověřuje před průchodem.
            int pocitadlo = 0;
            while (pocitadlo < 3)
            {
                Console.WriteLine($"while: {pocitadlo}");
                pocitadlo++;
            }

            // 9. DO/WHILE - tělo se provede alespoň jednou.
            int pokus = 0;
            do
            {
                Console.WriteLine($"do/while: {pokus}");
                pokus++;
            } while (pokus < 2);

            // 10. POLE - více hodnot stejného typu.
            int[] numbers = new int[5]; // Výchozí hodnoty jsou 0.
            numbers[0] = 10; // První index je 0.
            numbers[1] = 20;
            numbers[2] = 30;
            numbers[3] = 40;
            numbers[4] = 50; // Poslední index je 4.

            // Length vrací počet prvků pole.
            for (int i = 0; i < numbers.Length; i++)
            {
                Console.WriteLine($"numbers[{i}] = {numbers[i]}");
            }

            // Pole lze rovnou inicializovat hodnotami.
            int[] dalsiCisla = { 1, 2, 3 };
            // foreach prochází hodnoty prvků.
            foreach (int cislo in dalsiCisla)
            {
                Console.WriteLine(cislo);
            }

            // 11. VOLÁNÍ METOD
            int vysledek = Secti(5, 3);
            Console.WriteLine($"Soucet dvou cisel: {vysledek}");
            Console.WriteLine($"Soucet pole: {Sum(numbers)}");
            Console.WriteLine($"Prumer pole: {Average(numbers)}");
            Pozdrav("Eva");
        }
    }
}
