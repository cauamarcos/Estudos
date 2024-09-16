public class Paciente {
    String nome;
    double[] exames;

    Paciente(String nome, int n) {
        this.nome = nome;
        exames = new double[n];
    }
    String getNome() {return nome;}
    double resultado_amostra(int n) {return exames[n];}
    double media_resultados() {
        double soma = 0;
        for(int i = 0; i < exames.length; i++)
            soma += exames[i];
        return soma / exames.length;
    }
    String diagnostico() {
        double media = media_resultados();
        if(media < 140)
            return "Glicemia normal";
        else if(media < 200)
            return "Risco de diabetes";
        else
            return "Diabete Mellitus";
    }
    void inserir_resultado(double resultado) {
        double aux[] = exames;
        exames = new double[aux.length + 1];
        for(int i = 0; i < aux.length; i++)
            exames[i] = aux[i];
        exames[aux.length] = resultado;
    }
}
