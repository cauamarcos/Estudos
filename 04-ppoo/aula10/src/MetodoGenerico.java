public class MetodoGenerico {
    public <T, U, V> void souGenerico(T t, U u, V v) {
        System.out.println(t.getClass().getName() + ", " + u.getClass().getName() + ", " + v.getClass().getName());
    }
}