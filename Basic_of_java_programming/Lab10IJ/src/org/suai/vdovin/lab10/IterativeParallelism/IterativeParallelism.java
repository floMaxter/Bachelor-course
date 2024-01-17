package org.suai.vdovin.lab10.IterativeParallelism;

import java.util.*;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.stream.Collectors;

public class IterativeParallelism<T> {

    public static <T, R> R parallelize(int valueThreads, List<? extends T> list,
                                       Function<List<? extends T>, R> operation,
                                       Function<? super List<R>, R> finalOperation) throws Exception {
        if(valueThreads == 0) {
            throw new Exception("Invalid number of threads!");
        }

        List<R> result = new ArrayList<>();
        List<Thread> threads = new ArrayList<>();

        if(valueThreads > list.size()) {
            valueThreads = list.size();
        }


        int startIndex = 0;
        int countOfPart = list.size() / valueThreads;
        int additional = list.size() % valueThreads;

        for(int i = 0; i < valueThreads; i++) {
            int currIndex = startIndex;
            int finishIndex = ((i == 0) ? countOfPart + additional : countOfPart);

            Thread currentThread = new Thread(() -> {
               R cur = operation.apply(list.subList(currIndex, currIndex + finishIndex));
               synchronized (result) {
                   result.add(cur);
               }
            });

            threads.add(currentThread);
            startIndex += finishIndex;
        }

        try {
            for(Thread thread : threads) {
                thread.start();
            }
        } catch (InternalError ex) {
            System.out.println("Interrupted!");
        }


        try {
            for(Thread thread : threads) {
                thread.join();
            }
        } catch (InternalError ex) {
            System.out.println("Interrupted!");
        }

        return finalOperation.apply(result);
    }

    public <T> T minimum(int threads, List<? extends T> list, Comparator<? super T> comparator) throws Exception {
        Function<List<? extends T>, T> function = part -> Collections.min(part, comparator);
        return parallelize(threads, list, function, function);
    }

    public <T> T maximum(int threads, List<? extends T> list, Comparator<? super T> comparator) throws Exception {
        Function<List<? extends T>, T> function = part -> Collections.max(part, comparator);
        return parallelize(threads, list, function, function);
    }

    public <T> boolean all(int threads, List<? extends T> list, Predicate<? super T> predicate) throws Exception {
        return parallelize(threads, list, part -> part.stream().allMatch(predicate),
                part -> part.stream().allMatch(Boolean::booleanValue));
    }

    public <T> boolean any(int threads, List<? extends T> list, Predicate<? super T> predicate) throws Exception {
        return parallelize(threads, list, part -> part.stream().anyMatch(predicate),
                part -> part.stream().anyMatch(Boolean::booleanValue));
    }

    public <T> List<T> filter(int threads, List<? extends T> list, Predicate<? super T> predicate) throws Exception {
        return parallelize(threads, list, part -> part.stream().filter(predicate).collect(Collectors.toList()),
                part -> part.stream().flatMap(Collection::stream).collect(Collectors.toList()));
    }

    public <T, U> List<U> map(int threads, List<? extends T> list, Function<? super T, ? extends U> function) throws Exception {
        return parallelize(threads, list, part -> part.stream(). map(function).collect(Collectors.toList()),
                part -> part.stream().flatMap(Collection::stream).collect(Collectors.toList()));
    }

    public String join(int numberOfThreads, List<?> list) throws Exception {
        return parallelize(numberOfThreads, list, Objects::toString, Objects::toString);
    }
}