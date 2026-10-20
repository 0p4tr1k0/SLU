/*
//Přestupný rok
using System;

class Program
{
    static void Main()
    {
        Console.WriteLine("Zadej rok:");
        int rok = Convert.ToInt32(Console.ReadLine());

        if (rok % 4 == 0 && rok % 100 != 0 || rok % 400 == 0)
        {
            Console.WriteLine($"rok {rok} je prestupny.");
        }
        else
        {
            Console.WriteLine($"rok {rok} neni prestupny.");
        }
    }
}


//Přihlašování pomocí "admin" a "1234", jiné přihlašovací údaje neplatí
using System;

class Program
{
    static void Main()
    {
        // Načtení uživatelského jména
        Console.Write("Zadejte jméno: ");
        string username = Console.ReadLine();

        // Načtení hesla
        Console.Write("Zadejte heslo: ");
        string password = Console.ReadLine();

        // Ověření údajů
        if (username == "admin" && password == "1234")
        {
            Console.WriteLine("přihlášení úspěšné");
        }
        else
        {
            Console.WriteLine("neplatné přihlašovací údaje");
        }
    }
}


//uživatel zadá číslo dne a program vypíše název dne v týdnu, použito TryParse jako ošetření vstupu.
using System;

class Program
{
    static void Main()
    {
        Console.Write("Zadejte číslo dne (1-7): ");
        string vstup = Console.ReadLine();

        // Bezpečný převod pomocí TryParse
        if (int.TryParse(vstup, out int volba))
        {
            switch (volba)
            {
                case 1:
                    Console.WriteLine("Pondělí");
                    break;
                case 2:
                    Console.WriteLine("Úterý");
                    break;
                case 3:
                    Console.WriteLine("Středa");
                    break;
                case 4:
                    Console.WriteLine("Čtvrtek");
                    break;
                case 5:
                    Console.WriteLine("Pátek");
                    break;
                case 6:
                    Console.WriteLine("Sobota");
                    break;
                case 7:
                    Console.WriteLine("Neděle");
                    break;
                default:
                    Console.WriteLine("Neplatné číslo! Zadejte hodnotu od 1 do 7.");
                    break;
            }
        }
        else
        {
            Console.WriteLine("Chyba: Zadaný vstup není platné číslo.");
        }
    }
}*/


//Bankomat, kontrola stavu účtu, nesmí být záporný vklad ani výběr
using System;

class Program
{
    static void Main()
    {
        int stavUctu = 1000;
        int volba = -1;

        while (volba != 0)
        {
            Console.WriteLine("\nZadejte volbu:");
            Console.WriteLine("1 - Vklad hotovosti");
            Console.WriteLine("2 - Vyber hotovosti");
            Console.WriteLine("3 - Zustatek hotovosti");
            Console.WriteLine("0 - Konec programu");

            // Načtení volby uživatele
            if (!int.TryParse(Console.ReadLine(), out volba))
            {
                Console.WriteLine("Neplatný vstup, zadejte číslo.");
                continue;
            }

            switch (volba)
            {
                case 1:
                    Console.WriteLine("Volba vkladu.");
                    Console.Write("Vložte částku pro vklad: ");
                    if (int.TryParse(Console.ReadLine(), out int vklad))
                    {
                        if (vklad < 0)
                        {
                            Console.WriteLine("Nelze vložit zápornou částku!");
                        }
                        else
                        {
                            stavUctu += vklad;
                            Console.WriteLine($"Momentální stav účtu: nový zůstatek je {stavUctu}.");
                        }
                    }
                    else
                    {
                        Console.WriteLine("Neplatná částka.");
                    }
                    break;

                case 2:
                    Console.WriteLine("Volba výběru.");
                    Console.Write("Zadejte částku výběru: ");
                    if (int.TryParse(Console.ReadLine(), out int vyber))
                    {
                        if (vyber < 0)
                        {
                            Console.WriteLine("Nelze vybrat zápornou částku!");
                        }
                        else if (stavUctu < vyber)
                        {
                            Console.WriteLine("Nedostatek peněz na účtu.");
                        }
                        else
                        {
                            stavUctu -= vyber;
                            Console.WriteLine($"Momentální stav účtu: nový zůstatek je {stavUctu}.");
                        }
                    }
                    else
                    {
                        Console.WriteLine("Neplatná částka.");
                    }
                    break;

                case 3:
                    Console.WriteLine($"Váš zůstatek je {stavUctu}.");
                    break;

                case 0:
                    Console.WriteLine("Ukončování programu...");
                    break;

                default:
                    Console.WriteLine("Neplatná volba, zkuste to znovu.");
                    break;
            }
        }
    }
}