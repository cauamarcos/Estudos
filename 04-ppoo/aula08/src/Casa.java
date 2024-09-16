public class Casa extends Imovel {
    private boolean em_condominio;

    public Casa (String tipo, int tamanho, boolean em_condominio) {
        super(tipo, tamanho);
        this.em_condominio = em_condominio;
    }

    @Override
    public int calcularPremio() {
        if (em_condominio)
            return 5 * getTamanho();
        else
            return 7 * getTamanho();
    }

    @Override
    public String toString () {
        return "Tipo: " + getTipo() + " Tamanho: " + getTamanho() + " Em condominio fechado: " + em_condominio + " Premio: " + calcularPremio();
    }
    
}
