import java.util.Random;
import java.io.FileWriter;
import java.io.IOException;

/**
 * Essa é a classe principal da aplicação "A Jornada de Guidolf".
 * 
 * Neste jogo, o jogador pode mover seu personagem por vários ambientes, jogar
 * dados para obter vantagens e melhorias até que decida em diferentes locais do
 * mapa. O objetivo final é derrotar o Boss na Floresta Sombria.
 * 
 * Para que a quantidade de vantagens obtidas seja limitada, o jogador só pode
 * se movimentar pelo mapa por 5 vezes. Ao atingir esse limite, ele é
 * redirecionado
 * automaticamente para a Floresta Sombria, para que ocorra a batalha final.
 * 
 * Para jogar esse jogo, é preciso instanciar essa classe e chamar o método
 * "jogar".
 * 
 * Essa classe principal cria e inicializa todas as outras: ela cria os
 * ambientes, o analisador e começa o jogo. Ela também avalia e executa os
 * comandos
 * que o analisador retorna.
 * @author Alex Cyrillo, Cauã Marcos, Lucas de Castro Nizio
 */
public class Jogo {
    // analisador de comandos do jogo
    private Analisador analisador;
    // ambiente onde se encontra o jogador
    private Ambiente ambienteAtual;
    // numero de tentativas
    private int tentativas;
    private Jogador jogador;
    private Boss boss;
    private boolean terminado;

    private StringBuilder mensagem;
    private FileWriter writer;

    /**
     * Cria o jogo e incializa seu mapa interno.
     *
     */
    public Jogo() {
        abrirLog();
        jogador = new Jogador();
        criarAmbientes();
        analisador = new Analisador();
        tentativas = 5;
        boss = new Boss();
        terminado = false;
    }

    /**
     * Abre o arquivo de log para salvar informações do jogo.
     * 
     */
    private void abrirLog() {
        String nomeArquivo = "./files/relatorio_jogo.txt";
        try {
            writer = new FileWriter(nomeArquivo);
        } catch (IOException e) {
            System.out.println("Erro ao salvar o relatório da batalha no arquivo: " + e.getMessage());
        }
    }

    /**
     * Salva uma mensagem no arquivo de log.
     *
     * @param log A mensagem a ser salva no log.
     */
    private void salvarEmLog(String log) {
        try {
            writer.write("\n" + log + "\n");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * Fecha o arquivo de log.
     *
     */
    private void fecharLog() {
        try {
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * Cria todos os ambientes e liga as saidas deles
     *
     */
    private void criarAmbientes() {
        // criando os ambientes
        Ambiente taverna = new Ambiente("Taverna");
        Ambiente forja = new Ambiente("Forja");
        Ambiente temploSagrado = new Ambiente("Templo Sagrado");
        Ambiente arenaTreinamento = new Ambiente("Arena de Treinamento");
        Ambiente pracaCidade = new Ambiente("Praca da Cidade");
        Ambiente florestaSombria = new Ambiente("Floresta Sombria");

        // inicializando as saidas dos ambientes
        taverna.ajustarSaida("norte", pracaCidade);
        taverna.ajustarSaida("leste", arenaTreinamento);
        taverna.ajustarSaida("sul", forja);
        pracaCidade.ajustarSaida("leste", temploSagrado);
        pracaCidade.ajustarSaida("oeste", taverna);
        temploSagrado.ajustarSaida("norte", pracaCidade);
        temploSagrado.ajustarSaida("sul", florestaSombria);
        forja.ajustarSaida("norte", arenaTreinamento);
        forja.ajustarSaida("leste", florestaSombria);
        forja.ajustarSaida("oeste", taverna);
        arenaTreinamento.ajustarSaida("sul", forja);
        arenaTreinamento.ajustarSaida("oeste", taverna);

        ambienteAtual = pracaCidade; // o jogo comeca na Praça da Cidade
    }

    /**
     * Realiza a lógica principal do jogo. Lê os comandos do jogador e executa-os
     * até que o jogo termine. Gera mensagens indicando eventos e resultados do jogo.
     *
     * @param escrito comando escrito pelo jogador.
     * @return string descrevendo o estado do jogo ou eventos ocorridos.
     */
    public String jogar(String escrito) {
        // Aqui nós repetidamente lemos comandos e
        // os executamos até o jogo terminar.
        mensagem = new StringBuilder();
        if (tentativas == 0) {
            // Colocar o jogador na Floresta Sombria
            ambienteAtual = new Ambiente("Floresta Sombria");
            tentativas--;
            return ("Seu tempo acabou e um portal abriu sob seus pés. Voce se encontra perante a Boss, a sua única escolha é lutar ou morrer!!\n");
        }

        if (!terminado) {
            Comando comando = analisador.pegarComando(escrito);
            mensagem.append(processarComando(comando));

        } else {
            return ("Obrigado por jogar. Até mais! \n");
        }

        salvarEmLog(mensagem.toString());

        if (terminado)
            fecharLog();
        return mensagem.toString();
    }

    /**
     * Imprime a mensagem de abertura para o jogador.
     * 
     * @return  string com as boas vindas para o jogador.
     */
    public String imprimirBoasVindas() {
        return ("Bem-vindo a Jornada de Guidolf\n\nA sua jornada começa aqui, onde você irá assumir o papel de Guidolf, um corajoso guerreiro determinado a coletar recursos cruciais para a batalha épica que ocorrerá na Floresta Sombria contra o Boss.\n\nDigite 'ajuda' se você precisar de ajuda.\n");
    }

    /**
     * Dado um comando, processa-o (ou seja, executa-o)
     * 
     * @param comando O Comando a ser processado.
     * @return true se o comando finaliza o jogo.
     */
    private String processarComando(Comando comando) {
        if (comando.ehDesconhecido()) {
            return "Eu nao entendi o que voce disse...\n";
        }
        String palavraDeComando = comando.getPalavraDeComando();
        if (palavraDeComando.equals("ajuda")) {
            return imprimirAjuda();
        } else if (palavraDeComando.equals("ir")) {
            return irParaAmbiente(comando);
        } else if (palavraDeComando.equals("lutar")) {
            ambienteAtual = new Ambiente("Floresta Sombria");
            return batalharComBoss();
        } else if (palavraDeComando.equals("pocao")){
            return usarPocao();
        }
        return null;
    }

    /**
     * Exibe informações de ajuda.
     * Aqui nós imprimimos algo bobo e enigmático e a lista de palavras de comando
     * 
     * @return string com a mensagem de ajuda completa.
     */
    private String imprimirAjuda() {
        StringBuilder saida = new StringBuilder();
        saida.append("Você está perdido. Mas será que está sozinho?\n");
        saida.append("Você caminha pelo(a) ").append(ambienteAtual.getDescricao()).append("\n");
        saida.append("Suas palavras de comando são:\n");
        saida.append("   ").append(analisador.getComandosValidos());
        return saida.toString();
    }

    /**
     * Tenta ir em uma direcao. Se existe uma saída para lá entra no novo ambiente,
     * caso contrário imprime mensagem de erro.
     * 
     * @param comando comando que contém a direção para onde o jogador deve ir.
     * @return string indicando o resultado da tentativa de movimento.
     */
    private String irParaAmbiente(Comando comando) {
        // se não há segunda palavra, não sabemos pra onde ir...
        if (!comando.temSegundaPalavra()) {
            return "Ir pra onde?";
        }

        String direcao = comando.getSegundaPalavra();

        // Tenta sair do ambiente atual
        Ambiente proximoAmbiente = ambienteAtual.getSaida(direcao);

        if (proximoAmbiente == null) {
            return "Nao ha passagem!";
        } else {
            tentativas--;
            ambienteAtual = proximoAmbiente;
            return explorarAmbiente();
        }
    }

    /**
     * Exibe as informações da localização atual para o jogador.
     * 
     * @return string com a localização atual.
     */
    public String imprimirLocalizacaoAtual() {
        return (ambienteAtual.getDescricao());
    }

    /**
     * Esse método é responsável por verificar em qual ambiente o jogador
     * se encontra e analisar suas ações dentro de cada ambiente, como verificar
     * se o jogador obteve um bônus ao jogar um dado. Além disso, essa classe
     * concatena as strings que descrevem os acontecimentos à mensagem que será
     * salva no arquivo ao final da execução do programa.
     * 
     * @return string que será concatenada à mensagem salva no arquivo ao final da execução.
     */
    private String explorarAmbiente() {
        StringBuilder saida = new StringBuilder();
        Random random = new Random();
        int chanceRecurso = random.nextInt(101);

        if (ambienteAtual.getDescricao().equals("Forja") && ambienteAtual.isPrimeiraChegada()) {
            try {
                Thread.sleep(3000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            jogador.setVida(jogador.getVida() + 2);
            ambienteAtual.setPrimeiraChegada(false);
        }

        if (ambienteAtual.getDescricao().equals("Forja") || ambienteAtual.getDescricao().equals("Templo Sagrado")) {
            if (chanceRecurso > 30) {
                saida.append("Você encontrou um recurso!\n");
                saida.append(coletarRecurso());
            } else {
                saida.append("Não encontrou nenhum recurso.\n");
                jogador.setVida(jogador.getVida() - 2);
            }
        } else if (ambienteAtual.getDescricao().equals("Arena de Treinamento")) {
            int valorDado = random.nextInt(6) + 1;
            saida.append("Você jogou o dado e obteve um ").append(valorDado).append(".\n");
            if (valorDado == 6) {
                saida.append("Você ganhou 5 de ataque!\n");
                jogador.setAtaque(jogador.getAtaque() + 5);
            } else if (valorDado == 1) {
                saida.append("Você perdeu 2 de vida.\n");
                jogador.setVida(jogador.getVida() - 2);
            } else {
                saida.append("Você não ganhou nada!\n");
            }
            if (chanceRecurso > 75) {
                saida.append("Você encontrou uma espada lendária!\n");
                jogador.adicionarEspadaLendaria();
            }
        } else if (ambienteAtual.getDescricao().equals("Praça da Cidade")) {
            int valorDado = random.nextInt(6) + 1;
            saida.append("Você jogou o dado e obteve um ").append(valorDado).append(".\n");
            if (valorDado == 6) {
                saida.append("Você encontrou uma poção de cura!\n");
                jogador.adicionarPocaoDeCura();
            } else {
                saida.append("Você não encontrou nada.\n");
            }
        } else if (ambienteAtual.getDescricao().equals("Floresta Sombria")) {
            saida.append("Você entrou na Floresta Sombria e encontrou o Boss!\n");
        }

        saida.append(ambienteAtual.getDescricao() + " explorado(a)");

        return saida.toString();
    }

    /**
     * Sorteia um recurso bônus que será recebido pelo jogador.
     * 
     * @return string que indica qual item foi encontrado.
     */
    private String coletarRecurso() {
        Random random = new Random();
        int tipoRecurso = random.nextInt(3);

        switch (tipoRecurso) {
            case 0:
                jogador.adicionarPocaoDeCura();
                return "Você encontrou uma poção de cura!\n";
            case 1:
                jogador.adicionarArmaduraReforcada();
                return "Você encontrou uma armadura reforçada!\n";
            case 2:
                jogador.adicionarEspadaLendaria();
                return "Você encontrou uma espada lendária!\n";
        }
        return null;
    }

    /**
     * Atualiza o status do jogador, exibindo a quantidade de cada item,
     * sua vida e outras informações relevantes.
     * 
     * @return string com os dados atualizados do jogador.
     */
    public String exibirStatus() {
        StringBuilder saida = new StringBuilder();
        if (tentativas == -1)
            saida.append("Tempo ate o teleporte: ").append("0").append("\n\n");
        else
            saida.append("Tempo ate o teleporte: ").append(tentativas).append("\n\n");
        saida.append("Vida: ").append(jogador.getVida()).append("\n");
        saida.append("Ataque: ").append(jogador.getAtaque()).append("\n\n");
        saida.append("Equipamentos").append("\n");
        saida.append("Poções de Cura: ").append(jogador.getPocoesDeCura()).append("\n");
        saida.append("Armaduras Reforçadas: ").append(jogador.getArmadurasReforcadas()).append("\n");
        saida.append("Espadas Lendárias: ").append(jogador.getEspadasLendarias()).append("\n");

        return saida.toString();
    }

    /**
     * Realiza a batalha entre o jogador e o Boss. O método simula os ataques
     * e ações do jogador e do Boss até que um deles seja derrotado.
     *
     * @return string com o log da batalha.
     */
    private String batalharComBoss() {
        StringBuilder saida = new StringBuilder();
        // Enquanto o Boss e o jogador estiverem vivos
        // int turno = 1;
        if (boss.getVida() > 0 && jogador.getVida() > 0) {
            // Jogador ataca o Boss
            saida.append("Você ataca o Boss \n");
            int danoJogador = jogador.getAtaque();

            boss.setVida(boss.getVida() - danoJogador);
            if(boss.getVida() < 0)
                boss.setVida(0);
            saida.append("Você causou ").append(danoJogador).append(" de dano ao Boss. Vida do Boss: ")
                    .append(boss.getVida()).append("\n");

            saida.append("Você é atacado pelo Boss \n");
            int danoBoss = boss.atacar();
            if (danoBoss > boss.getAtaque()) {
                saida.append("O Boss utilizou uma habilidade especial\n");
                saida.append("Dano adicional: ").append(danoBoss - boss.getAtaque()).append("\n");
            } else {
                saida.append("O Boss atacou! \n");
            }
            jogador.setVida(jogador.getVida() - danoBoss);
            if(jogador.getVida() < 0)
                jogador.setVida(0);
            saida.append("O Boss causou ").append(danoBoss).append(" de dano a você. Sua vida: ")
                    .append(jogador.getVida()).append("\n");
        }

        if (boss.getVida() <= 0 || jogador.getVida() <= 0) {
            if (boss.getVida() <= 0)
                saida.append("\nVocê derrotou o Boss! Parabéns!\n");
            else
                saida.append("\nVocê foi derrotado pelo Boss. Game over!\n");
            terminado = true;
        }

        salvarEmLog(saida.toString());

        return saida.toString();
    }

    /**
     * Essa função representa a ação de um jogador ao utilizar uma poção de cura.
     * Atualiza o estado do jogador, aplicando os efeitos da poção.
     *
     * @return string indicando o uso da poção de cura.
     */

    private String usarPocao(){
        StringBuilder saida = new StringBuilder();
        jogador.usarPocaoDeCura();
        return saida.append("Você usou uma poção de cura! \n").toString();
    }

}
