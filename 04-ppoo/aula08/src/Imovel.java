public abstract class Imovel implements Segurado {
    private String tipo;
    private int tamanho;

    Imovel (String tipo, int tamanho) {
        this.tipo = tipo;
        this.tamanho = tamanho;
    }

    public String getTipo () {return tipo;}
    public int getTamanho () {return tamanho;}
}
