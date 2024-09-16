public abstract class Sabor extends Sorvete {
    private Sorvete sorvete;

    public Sabor(Sorvete sorvete) {
        this.sorvete = sorvete;
        setNome(sorvete.getNome());
    }

    public Sorvete getSorvete() {
        return sorvete;
    }
}
