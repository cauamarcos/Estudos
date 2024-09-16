import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.imageio.ImageIO;
import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

/**
 * A classe GUI representa a interface gráfica para o jogo "A Jornada de Guidolf".
 * Estende a classe Jogo para incorporar funcionalidades específicas de GUI.
 *
 * @author Alex Cyrillo de Sousa Borges
 */
public class GUI extends Jogo {
   private JFrame jogoGUI;
   private BufferedImage imagem;
   private JTextArea telaStats;
   private JTextField campoEntrada;
   private JTextArea telaSaida;
   private JButton botaoExecutar;
   private JPanel painelMapa;
   private JPanel painelStats;
   private JPanel painelES;
   private JLabel picLabel;
   private int larguraPadrao;
   private int alturaPadrao;
   private int larguraImagem;
   private int alturaImagem;

   /**
    * Construtor padrão para a classe GUI.
    * Inicializa os componentes da interface gráfica e configurações relacionadas.
    */
   public GUI() {
      super(); // Chama o construtor da classe pai (Jogo)

      // Configuração de dimensões padrão
      larguraPadrao = 950;
      alturaPadrao = 850;

      larguraImagem = 730;
      alturaImagem = 600;

      // Inicializa os componentes da GUI
      jogoGUI = new JFrame("A Jornada de Guidolf");
      telaSaida = new JTextArea();
      telaStats = new JTextArea();
      campoEntrada = new JTextField();
      botaoExecutar = new JButton("Enviar Comando");
      picLabel = new JLabel();

      // Adiciona um ouvinte de ação ao botão Executar
      botaoExecutar.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
               // Realiza ação ao clicar no botão Executar
               telaSaida.setText(jogar(campoEntrada.getText()));
               telaStats.setText(exibirStatus());
               campoEntrada.setText("");
               atualizarImagem(imprimirLocalizacaoAtual());
         }
      });

      montarTelaJogo();
   }

   /**
    * Monta a estrutura geral da tela do jogo, configurando o JFrame e chamando métodos para montar os painéis.
    */
   public void montarTelaJogo() {
      jogoGUI.setSize(larguraPadrao, alturaPadrao);
      jogoGUI.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      jogoGUI.setLayout(new BorderLayout());
      jogoGUI.setResizable(false);

      // Monta os painéis
      painelMapa();
      painelStats();
      painelES();
   }

   /**
    * Monta o painel do mapa, exibindo a imagem correspondente à localização atual.
    */
   private void painelMapa() {
      painelMapa = new JPanel();
      carregarImagem("Praca da Cidade");
      painelMapa.setLayout(new BoxLayout(painelMapa, BoxLayout.Y_AXIS));
      painelMapa.setPreferredSize(new Dimension(larguraImagem, alturaImagem));
      painelMapa.setBorder(BorderFactory.createTitledBorder("Sua Localizacao"));
      painelMapa.add(picLabel);
      jogoGUI.add(painelMapa, BorderLayout.CENTER);
   }

   /**
    * Monta o painel de estatísticas exibindo informações sobre o ambiente atual.
    */
   private void painelStats() {
      painelStats = new JPanel();
      painelStats.setLayout(new BoxLayout(painelStats, BoxLayout.Y_AXIS));
      painelStats.setPreferredSize(new Dimension(larguraPadrao - larguraImagem, alturaImagem));
      painelStats.setBorder(BorderFactory.createTitledBorder("Status"));
      painelStats.add(telaStats);

      telaStats.setEditable(false);
      telaStats.setPreferredSize(new Dimension(larguraPadrao - larguraImagem - 20, alturaImagem - 20));
      telaStats.setText(exibirStatus());
      telaStats.setLineWrap(true);
      telaStats.setWrapStyleWord(true);
      jogoGUI.add(painelStats, BorderLayout.EAST);
   }

   /**
    * Monta o painel de interação, contendo a área de saída de mensagens e o campo de entrada de comandos.
    */
   private void painelES() {
      painelES = new JPanel();
      painelES.setLayout(new BoxLayout(painelES, BoxLayout.Y_AXIS));
      painelES.setPreferredSize(new Dimension(larguraPadrao, alturaPadrao - alturaImagem));
      painelES.setBorder(BorderFactory.createTitledBorder("Area de Interacao"));

      // Monta a área de saída de mensagens
      montarTelaSaida(painelES);

      // Monta o campo de entrada de comandos
      montarCampoEntrada(painelES);

      jogoGUI.add(painelES, BorderLayout.SOUTH);
   }

   /**
    * Monta a área de saída de mensagens.
    *
    * @param paiNel O painel onde a área de saída será adicionada.
    */
   private void montarTelaSaida(JPanel paiNel) {
      telaSaida.setText(imprimirBoasVindas());
      telaSaida.setPreferredSize(new Dimension(larguraPadrao, alturaPadrao - alturaImagem - 60));
      telaSaida.setEditable(false);
      telaSaida.setLineWrap(true);
      telaSaida.setWrapStyleWord(true);

      JScrollPane telaSaidaScrollPane = new JScrollPane(telaSaida);
      telaSaidaScrollPane.setPreferredSize(new Dimension(larguraPadrao, alturaPadrao - alturaImagem - 60));
      telaSaidaScrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);

      // Adiciona a área de rolagem ao subpainel de mensagens
      paiNel.add(telaSaidaScrollPane);
   }

   /**
    * Monta o campo de entrada de comandos e o botão de execução.
    *
    * @param paiNel O painel onde o campo de entrada e o botão serão adicionados.
    */
   private void montarCampoEntrada(JPanel paiNel) {
      campoEntrada.setPreferredSize(new Dimension(larguraPadrao, 30));
      paiNel.add(campoEntrada);

      botaoExecutar.setPreferredSize(new Dimension(150, 30));
      paiNel.add(botaoExecutar);
   }

   /**
    * Carrega a imagem correspondente à posição atual do jogador.
    *
    * @param posicao A posição do jogador.
    */
   private void carregarImagem(String posicao) {
      try {
         String enderecoImagem = "./files/" + posicao + ".jpg";
         imagem = ImageIO.read(new File(enderecoImagem));
         picLabel = new JLabel(new ImageIcon(imagem));
      } catch (IOException e) {
         e.printStackTrace();
      }
   }

   /**
    * Atualiza a imagem exibida no painel do mapa com base na posição atual do jogador.
    *
    * @param posicao A posição atual do jogador.
    */
   private void atualizarImagem(String posicao) {
      painelMapa.remove(picLabel);
      carregarImagem(posicao);
      painelMapa.add(picLabel);
   }

   /**
    * Exibe a interface gráfica do jogo.
    */
   public void exibir() {
      jogoGUI.setVisible(true);
   }
}
