import java.util.ArrayList;

public class Agenda {
    private Contato contato;
    private ArrayList<Contato> Lista;

    public Agenda () {
        Lista = new ArrayList<>();
    }

    public void cadastrarPessoaFisica(String nome, String endereco, String email, String cpf, String estado_civil) {
        contato = new Pfisica(nome, endereco, email, cpf, estado_civil);
        Lista.add(0, contato);
    }

    public void cadastrarPessoaJuridica(String nome, String endereco, String email, String cnpj, int inscricao_estadual) {
        contato = new Pjuridica(nome, endereco, email, cnpj, inscricao_estadual);
        Lista.add(0, contato);
    }

    public Boolean removerContato(String id) {
        int pos = buscarContato(id);
        if (pos >= 0) {
            Lista.remove(pos);
            return true;
        }
        else
            return false;

    }

    private int buscarContato (String id) {
        for (int i = 0; i < Lista.size(); i++) {
            Contato c = Lista.get(i);
            if (c instanceof Pfisica) {
                if (((Pfisica)c).getCpf().equals(id))
                    return i;
            }
            else {
                if (((Pjuridica)c).getCnpj().equals(id))
                    return i;
            }
        }
        return -1;
    }

    @Override
    public String toString () {
        String dados = "";
        for (Contato c: Lista) {
            dados += c.toString();
            dados += "\n";
        }
        return dados;
    }
}
