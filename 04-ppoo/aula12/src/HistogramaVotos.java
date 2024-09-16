import java.io.Serializable;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class HistogramaVotos implements Serializable{
    private static final long serialVersionUID = 1L;
    private Map<String,Integer> hist;

    public HistogramaVotos() {
        hist = new HashMap<String,Integer>();
    }
    
    public void cadastrarVoto(String voto){
        if(hist.containsKey(voto)){
            hist.replace(voto, hist.get(voto)+1);
        }else{
            hist.put(voto, 1);
        }
    }  
    
    public void gerarRelatorioTela(){
        for (String voto : hist.keySet()) {
            System.out.printf("%-10s %3d%n",voto,hist.get(voto));
        }
    }

    public Map<String, Integer> getHistograma() {
        return Collections.unmodifiableMap(hist);//Retorna uma visão não modificável da coleção, garantindo o encapsulamento.
    }
  
}
