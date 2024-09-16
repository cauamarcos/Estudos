public class Cone extends Sorvete {
    public Cone(String nome) {
        setNome(nome);
    }
    
    @Override
    public int qtdBolas() {
        return 0;
    }

    @Override
    public double preco() {
        return 2.5;
    }
}
