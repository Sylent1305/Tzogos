# Tzogous 37 — Player Guide

**Tzogous 37** is a fast-paced, poker-inspired card game with bluffing, bonus-based scoring, and tactical use of jokers. The game is played in structured betting rounds with **pot-limit** rules, where each player's maximum raise is limited to the current pot size.

---

## Table of Contents

1. [Game Flow](#game-flow)  
2. [Pot-Limit Betting](#pot-limit-betting)  
3. [Player Actions](#player-actions)  
4. [Joker Rules](#joker-rules)  
5. [Card Values](#card-values)  
6. [Scoring](#scoring)  
7. [Tie Breaker](#tie-breaker)  
8. [Hand Probability (Reference)](#hand-probability-reference)  
9. [Best Two-Card Hand from Seven Cards](#best-two-card-hand-from-seven-cards)  
10. [Optional Variants](#optional-variants)  
11. [Example Round Summary](#example-round-summary)  
12. [License](#license)  

---

## Game Flow

1. Deal **7 cards** to each player.  
2. Each player places **one face-down card**.  
3. **First betting round** *(Pot-Limit)*: Check / Raise / Fold.  
4. Remaining players place **one face-up card**.  
5. **Second betting round** *(Pot-Limit)*.  
6. Reveal cards → Calculate score → Highest hand wins the pot.  
7. **Tie-breaker**: Tied players draw a card — highest wins.

---

## Pot-Limit Betting

- Raise amount cannot exceed the size of the current pot.  
- Minimum raise must at least match the previous bet or raise.  
- Two betting rounds occur (after face-down and face-up cards).

> Example: If the pot is 20 chips, the maximum a player may raise is 20.

---

## Player Actions

- **Check** – Pass without betting.  
- **Raise** – Bet up to the pot size.  
- **Call** – Match the current highest bet.  
- **Fold** – Forfeit the hand and exit the round.

---

## Joker Rules

- Use a joker **before acting** (Check / Raise / Fold).  
- **Replace** one opponent’s card (face-down or face-up) with a card from your hand.  
- After use, draw a new card to restore your hand to 7 cards.

> Jokers have value 0 and serve only for tactical manipulation.

---

## Card Values

| Card  | Value     |
|-------|-----------|
| 2–10  | Face value |
| J     | 11        |
| Q     | 12        |
| K     | 13        |
| A     | 14        |
| Joker | 0         |

---

## Scoring

Each player’s final hand consists of the two cards they played.  
Score = **sum of card values** + **one applicable bonus** (no further stacking).

### Bonus Combinations

| Combination               | Bonus Points |
|---------------------------|--------------|
| Flush (same suit)         | +3           |
| Straight (consecutive)    | +5           |
| Pair (same rank)          | +7           |
| Straight Flush            | +10          |

> **Note:**
> - “Straight” requires two cards of consecutive rank, including Ace–2 sequence (Ace counts as low).  
> - “Straight Flush” replaces separate Straight and Flush bonuses.  
> - Only one bonus applies per hand.

#### Corrected Examples

- **Flush only** (same suit, not consecutive):  
  10♥ + Q♥ → (10 + 12) + 3 = **25**

- **Straight only** (consecutive, different suits):  
  J♣ + Q♦ → (11 + 12) + 5 = **28**

- **Straight Flush** (consecutive and same suit):  
  J♥ + Q♥ → (11 + 12) + 10 = **33**

---

## Tie Breaker

If two or more players tie after scoring:

1. Each draws a card from the deck.  
2. Highest card wins the pot.  
3. If still tied, repeat the draw.

---

## Hand Probability (Reference)

Probability of obtaining specific two-card combinations when drawing two cards randomly from a standard 52-card deck:

| Combination       | Count | Probability (%) |
|-------------------|------:|----------------:|
| Pair              |    78 |            5.88 |
| Flush (non-SF)    |   264 |           19.91 |
| Straight (non-SF) |   144 |           10.86 |
| Straight Flush    |    48 |            3.62 |
| High Card         |   792 |           59.73 |

> **Note:**  
> - “Flush (non-SF)” refers to two cards of the same suit that are not consecutive.  
> - “Straight (non-SF)” refers to two consecutive ranks of different suits.

---

## Best Two-Card Hand from Seven Cards

Based on a 100 000-hand simulation, the probability that the best two-card combination drawn from a random 7-card hand falls into each category:

| Category        | Probability (%) |
|-----------------|-----------------|
| Straight Flush  | 60.55           |
| Straight        | 35.96           |
| Flush           | 3.49            |
| Pair            | <0.01           |
| High Card       | <0.01           |

> These probabilities illustrate how likely you are to be able to form each combination when selecting two cards from your full hand, informing decisions about which cards to keep or discard.

---

## Optional Variants

- **Two-Deck Mode**: Enables “Pair + Suit” bonus (treat as 10 bonus points total).  
- **Joker Limit**: Restrict each player to one joker use per round or game.  
- **Sudden Death**: After three tie-break draws, split the pot.

---

## Example Round Summary

1. Deal 7 cards.  
2. Player A plays face-down 9; Player B plays face-down Q.  
3. First betting round (pot = 10 → A raises 10 → pot = 20 → B calls).  
4. Players place face-up cards: A shows K; B shows Q.  
5. Second betting round (pot = 40 → B raises 30 → pot = 70 → A calls).  
6. Reveal:  
   - A: 9 + 13 = 22  
   - B: 12 + 12 = 24 + 7 (pair) = 31 → **B wins**.

---

## License

Distributed under the **MIT License**.  
See `LICENSE` for details.
  