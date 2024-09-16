public class App {
    public static void main(String[] args){
        MetodoGenerico mg = new MetodoGenerico();
        mg.souGenerico("A", 1, 0);
        mg.souGenerico(1, 1.0, 'f');
        mg.souGenerico(mg, "a", 'c');
        System.out.println();
        ClasseGenerica<String> classeGenerica1 = new ClasseGenerica<>("A", "B", "C");
        ClasseGenerica<Double> classeGenerica2 = new ClasseGenerica<>(1.0, 1.1, 2.0);
        classeGenerica1.setObjeto1("D");
        System.out.println(classeGenerica1.getObjeto1());
        System.out.println(classeGenerica1.getObjeto2());
        System.out.println(classeGenerica1.getObjeto3());
        System.out.println(classeGenerica2.getObjeto1());
        System.out.println(classeGenerica2.getObjeto2());
        System.out.println(classeGenerica2.getObjeto3());
    }
}
