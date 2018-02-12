from keras.callbacks import Callback

class InMemoryModelCheckpoint(Callback):
    def __init__(self, *, checkpoints=[], monitor='val_acc', load_best_on_train_end=True):
        super(InMemoryModelCheckpoint, self).__init__()
        self.checkpoints = checkpoints
        self.monitor = monitor
        self.load_best_on_train_end = load_best_on_train_end

    def on_epoch_end(self, epochs, logs = {}):
        self.checkpoints.append({
            'epochs': epochs,
            'logs': logs,
            'weights': self.model.get_weights(),
            })

    def on_train_end(self, logs={}):
        if not self.load_best_on_train_end:
            return

        if self.monitor in { 'val_acc' }: # Add if required
            best = getattr(__builtins__, 'max')
        else:
            best = getattr(__builtins__, 'min')
        best_point = best(self.checkpoints, key=lambda e: e['logs'].get(self.monitor) or 0.) # Avoid TypeError
        self.model.set_weights(best_point['weights'])
