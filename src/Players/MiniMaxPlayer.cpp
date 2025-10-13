#include "MiniMaxPlayer.h"

void MiniMaxPlayer::makeMove(Board& board) const {
  int bestScore = 1'000'000'000;
  int bestFromRow = -1;
  int bestFromCol = -1;
  int bestToRow = -1;
  int bestToCol = -1;

  for (Piece* piece : board.getAlivePieces(this->color)) {
    for (array<int, 2> move : piece->getPossibleMoves(board)) {
      int fromRow = piece->getRow();
      int fromCol = piece->getCol();
      int toRow = move[0];
      int toCol = move[1];

      board.movePiece(fromRow, fromCol, toRow, toCol);
      int score = minimax(board, maxDepth - 1, -100'000'000, 100'000'000, true);
      board.undoLastMove();

      if (score < bestScore) {
        bestScore = score;
        bestFromRow = fromRow;
        bestFromCol = fromCol;
        bestToRow = toRow;
        bestToCol = toCol;
      }
    }
  }

  board.movePiece(bestFromRow, bestFromCol, bestToRow, bestToCol);
  std::cout << "Robot plays: (" << bestFromRow << ", " << bestFromCol << ") to (" << bestToRow
            << ", " << bestToCol << ")" << std::endl
            << std::endl;
};

int MiniMaxPlayer::minimax(
    Board& board, int depth, int alpha, int beta, bool isMaximizingPlayer
) const {
  Game* game = Game::getInstance();

  if (depth == 0 || game->getGameState() != Game::State::PLAY) {
    return evaluate(board);
  }

  if (isMaximizingPlayer) {
    int maxEval = -1'000'000'000;

    for (Piece* piece : board.getAlivePieces(this->color)) {
      for (array<int, 2> move : piece->getPossibleMoves(board)) {
        int fromRow = piece->getRow();
        int fromCol = piece->getCol();
        int toRow = move[0];
        int toCol = move[1];

        board.movePiece(fromRow, fromCol, toRow, toCol);
        int eval = minimax(board, depth - 1, alpha, beta, false);
        board.undoLastMove();

        maxEval = std::max(maxEval, eval);
        alpha = std::max(alpha, eval);
        if (beta <= alpha) {
          break;
        }
      }
    }

    return maxEval;
  } else {
    int minEval = 1'000'000'000;

    for (Piece* piece : board.getAlivePieces(Color::flipped(this->color))) {
      for (array<int, 2> move : piece->getPossibleMoves(board)) {
        int fromRow = piece->getRow();
        int fromCol = piece->getCol();
        int toRow = move[0];
        int toCol = move[1];

        board.movePiece(fromRow, fromCol, toRow, toCol);
        int eval = minimax(board, depth - 1, alpha, beta, true);
        board.undoLastMove();

        minEval = std::min(minEval, eval);
        beta = std::min(beta, eval);
        if (beta <= alpha) {
          break;
        }
      }
    }

    return minEval;
  }
};

int MiniMaxPlayer::evaluate(const Board& board) const {
  Game* game = Game::getInstance();
  Color::Value opponentColor = Color::flipped(this->color);

  Game::State state = game->getGameState();
  if (state == Game::State::CHECKMATE) {
    return game->getCurrentPlayer()->getColor() == this->color ? -10'000'000 : 10'000'000;
  } else if (state == Game::State::STALEMATE || state == Game::State::DRAW) {
    return 0;
  } else {
    int score = 0;

    for (Piece* piece : board.getAlivePieces(this->color)) {
      score += piece->getValue();
    }

    for (Piece* piece : board.getAlivePieces(opponentColor)) {
      score -= piece->getValue();
    }

    return score;
  }
};