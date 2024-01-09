package utils;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class FileUtils {
    public static File creaFile(String nomeFile) {
        System.out.println("Creazione del file in corso...\n");
        File doc = new File(nomeFile);
        return doc;
    }

    public static void scriviFile(File f, String testo) {
        PrintWriter print = null;

        try {
            print = new PrintWriter(f);
            System.out.println("Scrittura sul file in corso...\n");
            print.println(testo);
            print.close();
        } catch (FileNotFoundException e) {
            System.err.println("File non valido");
        } finally {
            if (null!=print) {
                print.close();
            }
        }
    }

    public static void leggiFile(File f) {
        try {
            System.out.println("Contenuto del file: ");
            Scanner s = new Scanner(f);
            while(s.hasNextLine()) {
                System.out.println(s.nextLine());
            }
            s.close();
            System.out.println("\n\nIl file si può trovare nella cartella del progetto");
        } catch (FileNotFoundException e) {
            System.out.println("File non valido");
        }
    }
}
