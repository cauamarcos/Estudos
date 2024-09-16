import javax.swing.JFrame;
import javax.swing.JButton;
import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class Calculadora {
    private JFrame janela;
    private String texto;
    private JTextField campoTexto;
    private JButton zero;
    private JButton um;
    private JButton dois;
    private JButton tres;
    private JButton quatro;
    private JButton cinco;
    private JButton seis;
    private JButton sete;
    private JButton oito;
    private JButton nove;
    private JButton igual;
    private JButton mais;
    private JButton menos;
    private JButton barra;
    private JButton asterisco;
    private JButton ponto;
    private JButton ac;

    public Calculadora() {
        janela = new JFrame("Calculadora");
        texto = "";
        campoTexto = new JTextField();
        zero = new JButton("0");
        um = new JButton("1");
        dois = new JButton("2");
        tres = new JButton("3");
        quatro = new JButton("4");
        cinco = new JButton("5");
        seis = new JButton("6");
        sete = new JButton("7");
        oito = new JButton("8");
        nove = new JButton("9");
        igual = new JButton("=");
        mais = new JButton("+");
        menos = new JButton("-");
        barra = new JButton("/");
        asterisco = new JButton("*");
        ponto = new JButton(".");
        ac = new JButton("AC");

        zero.addActionListener(
            new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    texto += "0";
                    campoTexto.setText(texto);
                }
        });
        um.addActionListener(
            new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    texto += "1";
                    campoTexto.setText(texto);
                }
        });

        dois.addActionListener(
            new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    texto += "2";
                    campoTexto.setText(texto);
                }
        });
        tres.addActionListener(
            new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    texto += "3";
                    campoTexto.setText(texto);
                }
        });
        quatro.addActionListener(
            new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    texto += "4";
                    campoTexto.setText(texto);
                }
        });
        cinco.addActionListener(
            new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    texto += "5";
                    campoTexto.setText(texto);
                }
        });
        seis.addActionListener(
            new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    texto += "6";
                    campoTexto.setText(texto);
                }
        });
        sete.addActionListener(
            new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    texto += "7";
                    campoTexto.setText(texto);
                }
        });
        oito.addActionListener(
            new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    texto += "8";
                    campoTexto.setText(texto);
                }
        });
        nove.addActionListener(
            new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    texto += "9";
                    campoTexto.setText(texto);
                }
        });
        mais.addActionListener(
            new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    texto += "+";
                    campoTexto.setText(texto);
                }
        });
        menos.addActionListener(
            new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    texto += "-";
                    campoTexto.setText(texto);
                }
        });
        asterisco.addActionListener(
            new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    texto += "*";
                    campoTexto.setText(texto);
                }
        });
        barra.addActionListener(
            new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    texto += "/";
                    campoTexto.setText(texto);
                }
        });
        ponto.addActionListener(
            new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    texto += ".";
                    campoTexto.setText(texto);
                }
        });
        ac.addActionListener(
            new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    texto = "";
                    campoTexto.setText(texto);
                }
        });
        igual.addActionListener(
            new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    
                }
        });
        
        montarJanela();
    }
    private void montarJanela() {
        janela.setSize(350, 250);
        janela.setLayout(new BorderLayout());

        JPanel painelSup = new JPanel();
        painelSup.setLayout(new BorderLayout());
        painelSup.add(ac, BorderLayout.WEST);
        painelSup.add(campoTexto, BorderLayout.CENTER);
        janela.add(painelSup, BorderLayout.NORTH);

        JPanel painelCentro = new JPanel();
        painelCentro.setLayout(new GridLayout(4, 4));
        painelCentro.add(sete);
        painelCentro.add(oito);
        painelCentro.add(nove);
        painelCentro.add(barra);
        painelCentro.add(quatro);
        painelCentro.add(cinco);
        painelCentro.add(seis);
        painelCentro.add(asterisco);
        painelCentro.add(um);
        painelCentro.add(dois);
        painelCentro.add(tres);
        painelCentro.add(menos);
        painelCentro.add(zero);
        painelCentro.add(ponto);
        painelCentro.add(mais);
        painelCentro.add(igual);
        janela.add(painelCentro, BorderLayout.CENTER);
    }
    public void exibir() {
        janela.setVisible(true);
    }
}
