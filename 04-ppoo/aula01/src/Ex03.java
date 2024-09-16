import java.util.Scanner;

public class Ex03 {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner (System.in);
        System.out.println("Frase a ser analisada: ");
        String frase = sc.nextLine();
        sc.close();
        String[] palavras = frase.split(" ");
        String palavra = "";
        int numVogais = 0;
        char[] vogais = {'a', 'e', 'i', 'o', 'u'};
        for(int i = 0; i < palavras.length; i++) {
            int cont = 0;
            for(int j = 0; j < palavras[i].length(); j++) {
                for(int k = 0; k < 5; k++) {
                    if(palavras[i].charAt(j) == vogais[k])
                        cont++;
                }
            }
            if(cont > numVogais) {
                numVogais = cont;
                palavra = palavras[i];
            }
        }
        System.out.println("Palavra com mais vogais: " + palavra);
        System.out.println("Tamanho: " + numVogais);
    }
}
