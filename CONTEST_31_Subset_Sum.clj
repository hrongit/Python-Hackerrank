(comment "

ques link -https://www.hackerrank.com/contests/int213-contest31/challenges/subset-sum/leaderboard
    }
}

")



  (require '[clojure.data.int-map :as i])
(let [N (Integer/parseInt (read-line))
      A (map #(Long/parseLong %) (.split (read-line) " "))
      sortedA (reverse (sort A))
      partials (reductions + sortedA)
      tops (last partials)
      T (Integer/parseInt (read-line))
      cases (for [_ (range T)] (Long/parseLong (read-line)))
      posmap (loop [pos 1
                   [case1 & caser :as cases] (sort cases)
                   [part1 & partr :as partials] partials
                   posmap (i/int-map)]
                (cond
                    (nil? case1) posmap
                    (> case1 tops)
                      (recur pos caser partials posmap)
                    (>= part1 case1)
                      (recur pos caser partials
                        (assoc posmap case1 pos))
                    true (recur (inc pos) cases partr posmap)))]
    (doseq [case cases]
        (println (get posmap case -1))))