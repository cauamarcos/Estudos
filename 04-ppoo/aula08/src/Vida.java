public class Vida implements Segurado {
    private int idade;
    private char genero;

    public Vida (int idade, char genero) {
        this.idade = idade;
        this.genero = genero;
    }

    @Override
    public int calcularPremio() {
        if (idade < 60)
            return ((idade/10) + 1) * 100;
        else if (genero == 'F')
            return 700;
        else
            return 800;
    }

    @Override
    public String toString () {
        return "Idade: " + idade + " Genero: " + genero + " Premio: " + calcularPremio();
    }
}
