public abstract class Sorvete {
    private String nome;

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public abstract int qtdBolas();

    public abstract double preco();
}
