public class Apartamento extends Imovel {
    private int numero_andares;

    public Apartamento (String tipo, int tamanho, int numero_andares) {
        super(tipo, tamanho);
        this.numero_andares = numero_andares;
    }

    @Override
    public int calcularPremio() {
        if (numero_andares < 4)
            return 3 * getTamanho();
        else
            return 4 * getTamanho();
    }
    
    @Override
    public String toString () {
        return "Tipo: " + getTipo() + " Tamanho: " + getTamanho() + " Numero de andares do predio: " + numero_andares + " Premio: " + calcularPremio();
    }
}
