import java.io.*;
import java.util.Map;

public class ManipuladoraArquivos {
    public static HistogramaVotos lerArquivoBinario(String nomeArquivo) {
        HistogramaVotos hv = null;
        try {ObjectInputStream ois = new ObjectInputStream(new FileInputStream(nomeArquivo));
            hv = (HistogramaVotos)ois.readObject();
        }
        catch (Exception e) {
            System.out.println(e.getMessage());
        }
        return hv;
    }

    public static HistogramaVotos lerArquivoTexto(String nomeArquivo) {
        try {
            BufferedReader arq = new BufferedReader(new FileReader(nomeArquivo));
            String linha = arq.readLine();
            while(linha != null) {
                String[] campos = linha.split(",");
                
                linha = arq.readLine();
            }
            arq.close();
        }
        catch(FileNotFoundException e) {
            System.out.println("Impossivel abrir o arquivo " + nomeArquivo);
        }
        catch(IOException e) {
            System.out.println("Problema na leitura do arquivo " + nomeArquivo);
        }
    }

    public static void gerarArquivoTexto(Map<String, Integer> hv, String nomeArquivo) {
        try(FileWriter arq = new FileWriter(nomeArquivo)) {
            for (HistogramaVotos v : hv) {
                
            }
        }
    }
}
