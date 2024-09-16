public class Pfisica extends Contato {
    private String cpf;
    private String estado_civil;

    public Pfisica (String nome, String endereco, String email, String cpf, String estado_civil) {
        super(nome, endereco, email);
        this.cpf = cpf;
        this.estado_civil = estado_civil;
    }

    public String getCpf () {return cpf;}

    public String toString() {
        return super.toString() + " Cpf: " + cpf + " Estado civil: " + estado_civil;
    }
}
