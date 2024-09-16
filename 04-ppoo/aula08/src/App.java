import java.util.ArrayList;

public class App {
    public static void main(String[] args) throws Exception {
        ArrayList<Segurado> lista = new ArrayList<>();
        Segurado a = new Casa("casa", 200, true);
        Segurado b = new Apartamento("apartamento", 200, 2);
        Segurado c = new Vida(10, 'M');
        Segurado d = new Vida(60, 'F');
        lista.add(0, a);
        lista.add(0, b);
        lista.add(0, c);
        lista.add(0, d);
        for (Segurado s: lista) {
            System.out.println(s.toString());
        }
    }
}
